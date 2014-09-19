#ifndef BITCOMPRESSEDVECTOR_H_
#define BITCOMPRESSEDVECTOR_H_
#include <cmath>
#include <vector>
#include <string>

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
        free( m_pData );
    }
    
//inline function list
public:
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

inline uint64_t offsetForColumns(uint64_t columns){
    uint64_t sum = 0;

    for(uint64_t i = 0; i < columns ; i++){
        sum += m_BitsForEachColumn[i];
    }

    return sum;
}

//implements of all the interfaces
public:
    uint64_t getColumn()const{
         
    }

    void resize(size_t size){
         
    }
    
    void clear(){
        m_iSize = 0;
        free(m_pData);
        m_pData = nullptr;
    }

    T get(size_t row,size_t column){
    
    }

    uint64_t set(size_t row, size_t column, T &value){
    
    }

    virtual size_t getSize()const{
        return m_iSize;
    }

private: 
    //the number of columns and rows
    size_t m_iColumns;
    size_t m_iRows;
    size_t m_iSize;

    tBitSizeList m_BitsForEachColumn;
    tStorageUnit *m_pData;
};

#endif
