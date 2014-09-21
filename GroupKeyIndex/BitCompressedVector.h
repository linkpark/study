#ifndef BITCOMPRESSEDVECTOR_H_
#define BITCOMPRESSEDVECTOR_H_
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>

#include "BaseAttributeVector.h"

template <class T>
class BitCompressedVector final:public BaseAttributeVector<T>{
private:
    typedef T tTypeName;
    typedef uint64_t tStorageUnit;
    typedef std::vector< uint64_t > tBitSizeList;
    const static uint64_t bitWidth = sizeof( tStorageUnit ) * 8;

public:
    BitCompressedVector(size_t columns,size_t rows,tBitSizeList bitsForEachColumn = {} )
        :m_pData(nullptr),m_iColumns(columns),m_iRows(rows),m_BitsForEachColumn(bitsForEachColumn){
        //if the bits is unset, then behave like a normal vector
        if( 0 == m_BitsForEachColumn.size() ){
            m_BitsForEachColumn = std::vector< uint64_t >( m_iColumns, sizeof(T) * 8 );
        } 
    }

    ~BitCompressedVector(){
    }
    
//implements of all the interfaces
public:
    uint64_t getColumns()const{
        return m_iColumns;               
    }
    
    //resize the memory
    void resize(size_t numberOfBlocks){
         
    }
    
    void clear(){
        m_iSize = 0;
        free(m_pData);
        m_pData = nullptr;
    }

    T get(size_t row,size_t column){
        T result;

        auto offset = blockOffset(row);
        auto colOffset = offsetForColumns(column);
        auto block = blockPosition(row) + ( offset + colOffset ) / bitWidth;
        
        colOffset = ( offset + colOffset ) % bitWidth;
        
        uint64_t bounds = bitWidth - colOffset;
        uint64_t baseMask = ( 1ull << m_BitsForEachColumn[column] ) - 1ull;

        result = (( m_pData[ block ] >> colOffset ) & baseMask);
        
        //deal with the bound situation        
        if(bounds < m_BitsForEachColumn[ column ]){
            colOffset = m_BitsForEachColumn[ column ] - bounds;
            baseMask = ( 1ull << colOffset ) - 1ull;
            result |= ((baseMask & m_pData[block + 1] ) << bounds);
        }

        return result;
    }

    void set(size_t row, size_t column, T &value){ 
        auto offset = blockOffset(row);
        auto colOffset = offsetForColumns(column);
        auto block =  blockPosition(row) + ( offset + colOffset ) / bitWidth ;

        colOffset = ( offset + colOffset ) % bitWidth;

        uint64_t bounds = bitWidth - colOffset;
        uint64_t baseMask = ( 1ull << m_BitsForEachColumn[column] ) - 1ull;
        uint64_t mask = ~(baseMask << colOffset);

        m_pData[ block ] &= mask;
        m_pData[ block ] |= (((uint64_t)value & baseMask) << colOffset);
        
        //in the bounds situation
        if( bounds < m_BitsForEachColumn[column] ){
            mask = ~(baseMask >> bounds);
            m_pData[ block + 1 ] &= mask;
            m_pData[ block + 1 ] |= (( (uint64_t)value & baseMask ) >> bounds);
        }
    }

    virtual size_t getSize()const{
        return m_iSize;
    }

    void allocData(){
        uint64_t blockNumbers = (tupleWidth() * m_iRows * m_iColumns) / bitWidth + 1;
        m_pData = allocMemory(blockNumbers); 
        m_iSize = sizeof(tStorageUnit) * blockNumbers;
    }
    
//inline function list
private:
    inline uint64_t tupleWidth()const{
        uint64_t sum = 0;

        for(uint64_t i = 0; i < m_BitsForEachColumn.size(); i++){
            sum += m_BitsForEachColumn[i];
        }

        return sum;
    } 

    inline uint64_t blockPosition(uint64_t row)const{
        return (tupleWidth() * row) / bitWidth;
    }           

    inline uint64_t blockOffset(uint64_t row)const{
        return (tupleWidth() * row) % bitWidth; 
    }
 
    inline uint64_t blockNumbers(uint64_t rows)const{
        return ((rows * tupleWidth()  + bitWidth - 1 ) / bitWidth);
    }

    inline uint64_t offsetForColumns(uint64_t columns){
        uint64_t sum = 0;

        for(uint64_t i = 0; i < columns ; i++){
            sum += m_BitsForEachColumn[i];
        }

        return sum;
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
    uint64_t m_iColumns;
    uint64_t m_iRows;

    //the size of the storage unit
    uint64_t m_iSize;

    //the number of storage blocks
    uint64_t m_iBlocks;

    tBitSizeList m_BitsForEachColumn;
    tStorageUnit *m_pData;
};

#endif
