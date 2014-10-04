#ifndef BITCOMPRESSEDVECTOR_H_
#define BITCOMPRESSEDVECTOR_H_
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

#include "BaseAttributeVector.h"

template <class T>
class BitCompressedVector final:public BaseAttributeVector<T>{
private:
    typedef T tTypeName;
    typedef uint64_t tStorageUnit;
    const static uint64_t bitWidth = sizeof( tStorageUnit ) * 8;

public:
    BitCompressedVector(size_t rows,size_t bitsForColumn = {} )
        :m_pData(nullptr),m_iRows(rows),m_BitsForEachColumn(bitsForEachColumn){
        //if the bits is unset, then behave like a normal vector
        if( 0 == m_BitsForEachColumn.size() ){
            m_BitsForColumn = sizeof(T) * 8;
        } 
    }

    ~BitCompressedVector(){
    }
    
//implements of all the interfaces
public:
    //resize the memory
    void resize(size_t rowsNumber){
        tStorageUnit *data;
        uint64_t blockNumbers = rowsNumber  * m_BitsForColumn / bitWidth + 1;  
       
        data = allocMemory(blockNumbers);
        
        memcpy( data , m_pData, m_iSize);
        clear();
        m_pData = data;

        m_iSize = blockNumbers * sizeof(tStorageUnit);
    }
    
    void clear(){
        m_iSize = 0;
        free(m_pData);
        m_pData = nullptr;
    }

    T get(size_t row){
        T result;

        auto offset = blockOffset(row);
        auto block = blockPosition(row) + offset / bitWidth;
        
        auto colOffset =  offset  % bitWidth;
        
        uint64_t bounds = bitWidth - colOffset;
        uint64_t baseMask = ( 1ull << m_BitsForColumn ) - 1ull;

        result = (( m_pData[ block ] >> colOffset ) & baseMask);
        
        //deal with the bound situation        
        if(bounds < m_BitsForColumn){
            colOffset = m_BitsForColumn - bounds;
            baseMask = ( 1ull << colOffset ) - 1ull;
            result |= ((baseMask & m_pData[block + 1] ) << bounds);
        }

        return result;
    }

    void set(size_t row, T &value){ 
        auto offset = blockOffset(row);
        auto block =  blockPosition(row) + offset / bitWidth ;

        auto colOffset = offset % bitWidth;
    
        //calculate the position of one number 
        uint64_t bounds = bitWidth - colOffset;
        uint64_t baseMask = ( 1ull << m_BitsForColumn ) - 1ull;
        uint64_t mask = ~( baseMask << colOffset );
        
        m_pData[ block ] &= mask;
        m_pData[ block ] |= (((uint64_t)value & baseMask) << colOffset);
        
        //in the bounds situation
        if( bounds < m_BitsForColumn ){
            mask = ~(baseMask >> bounds);
            m_pData[ block + 1 ] &= mask;
            m_pData[ block + 1 ] |= (( (uint64_t)value & baseMask ) >> bounds);
        }
    }

    virtual size_t getSize()const{
        return m_iSize;
    }

    void allocData(){
        uint64_t blockNumbers = (m_BitsForColumn * m_iRows ) / bitWidth + 1;
        m_pData = allocMemory(blockNumbers); 
        m_iSize = sizeof(tStorageUnit) * blockNumbers;
    }
    
//inline function list
private: 
    inline uint64_t blockPosition(uint64_t row)const{
        return (m_BitsForColumn * row) / bitWidth;
    }           

    inline uint64_t blockOffset(uint64_t row)const{
        return (m_BitsForColumn * row) % bitWidth; 
    }
 
    inline uint64_t blockNumbers(uint64_t rows)const{
        return ((rows * m_BitsForColumn  + bitWidth - 1 ) / bitWidth);
    }

    inline tStorageUnit* allocMemory(uint64_t blockNumbers){
         auto data = static_cast< tStorageUnit* >( malloc(blockNumbers * sizeof(tStorageUnit)) );

        if(nullptr == data){
            throw std::bad_alloc();
        }

        return data;
    }


private: 
    //the number of columns and rows
    uint64_t m_iRows;

    //the size of the storage unit
    uint64_t m_iSize;

    //the number of storage blocks
    uint64_t m_iBlocks;

    size_t m_BitsForColumn;
    tStorageUnit *m_pData;
};

#endif
