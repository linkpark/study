/*
 * =================================================================
 *
 *            Filename:    GroupKeyIndex.h
 *
 *         Description:    group key index class,implement of the group key
 *                         index.
 *             Version:    v1.0
 *             Created:    2014-10-05 11:28
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifdef GROUPKEYINDEX_H_
#define GROUPKEYINDEX_H_
#include <vector>
#include <map>
#include <memory>
#include <cmath>

#include "BitCompressedVector.h"
#include "ColumnIndexBase.h"
#include "BaseDictionary.h"
#include "OrderVectorDictionary.h"

class DeltaData;

template <class T>
class GroupKeyIndex final:public ColumnIndexBase<T>{
//defination part
private:
    typedef OrderVectorDictionary< T > dic_t;
    typedef BitCompressedVector< uint64_t > vector_t;
    typedef std::shared_ptr<vector_t> vector_ptr_t;
    typedef std::shared_ptr<dic_t> dic_ptr_t; 

public:
    vector<uint64_t> searchByKey( T &key );
    vector<uint64_t> searchByKeyRange( T &start, T &end );
    
    void batchImport( vector<T> &dataList );

    T searchByRowId( uint64_t rowId );

public:
    GroupKeyIndex():
        m_IndexVector(nullptr),
        m_PositionVector(nullptr),
        m_AttributeVector(nullptr){

        m_Dictionary = std::make_shared< dic_t >(); 
    }

    void importOriginData(std::vector<T> &originData){
        value_id_t dicNumber;
        dicNumber = m_Dictionary -> constructDictionaryByVector( originData );

        if(dicNumber == 0)
            throw std::logic_error("empty dictionary");
        
        generateAttributeVector( originData );
    } 


    ~GroupKeyIndex(){ 
    }

//forbidden copy constructe function
private:
    GroupKeyIndex(const GroupKeyIndex<T>&);
    GroupKeyIndex<T>& operator=(const GroupKeyIndex<T>&);

    inline void generateAttributeVector( std::vector<T> &originData ){
        uint64_t valueId;
        m_Rows = originData.size();
        m_BitsForColumn = (size_t)( log2(rows) );
        m_AttributeVector = std::make_shared< vector_ptr_t >( rows,bitsForColumn );
        m_AttributeVector.allocData();

        //set the attribute vector
        for(size_t i = 0; i < originData.size() ; ++i){
            valueId = m_Dictionary->findValueIdByValue( originData[i] );
            m_AttributeVector.set( i , valueId );
        }
    }

    inline void generateIndexVector(){
        size_t dicSize = m_Dictionary->getSize();
        std::vector< long long > valueCount( dicSize, 0 );
        
        for(size_t i = 0; i < m_Rows ; i++){
            valueCount[ m_AttributeVector->get(i) ]++;
        }

        m_IndexVector = std::make_shared< vector_ptr_t >( dicSize, m_BitsForColumn );
        m_IndexVector->set( 0 , 0 );

        for(size_t i = 0; i < dicSize ; i++){
            m_IndexVector->set(i+1, (m_IndexVector->get(i) + valueCount[i]) );
        }
    }

    inline void generatePositionVector(){
        std::vector< long long > positionVectorTemp( m_Rows , -1 );
        size_t offset;

        for(size_t i = 0 ;i < m_Rows; ++i ){
            offset = m_IndexVector->get( m_AttributeVector->get(i) );  
            while( positionVectorTemp[ offset ] != -1 ){
                offset++;
            }

            positionVectorTemp[ offset ] = i;
        }

        m_PositionVector = std::make_shared< vector_ptr_t >( m_Rows, m_BitsForColumn );
        
        for(int i = 0; i < m_Rows; ++i){
            m_PositionVector->set( i , positionVectorTemp[i] );
        }
    }
    
private:
    int mergeProcess(){}

private:
    //main data structure
    vector_ptr_t m_IndexVector;
    vector_ptr_t m_PositionVector;
    vector_ptr_t m_AttributeVector;
    dic_ptr_t m_Dictionary;
    size_t m_Rows;
    size_t m_BitsForColumn;

    DeltaData m_CDeltaData;
};
#endif

