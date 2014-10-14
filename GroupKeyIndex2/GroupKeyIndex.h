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
    
    batchImport( vector<T> &dataList );

    T searchByRowId( uint64_t rowId );

public:
    GroupKeyIndex(){
        m_Dictionary = std::make_shared< dic_t >(); 
    }

    void importOriginData(std::vector<T> &originData){
        value_id_t dicNumber;
        dicNumber = m_Dictionary -> constructDictionaryByVector( originData );

        if(dicNumber == 0)
            throw std::logic_error("empty dictionary");
        
        size_t rows = originData.size();
        size_t bitsForColumn = (size_t)(log2(rows));
        uint64_t valueId;

        m_AttributeVector = std::make_shared< vector_ptr_t >( rows,bitsForColumn );
        m_AttributeVector.allocData();

        //set the attribute vector
        for(size_t i = 0; i < originData.size() ; ++i){
            valueId = m_Dictionary->findValueIdByValue( originData[i] );
            m_AttributeVector.set( i , valueId );
        }
    } 

    ~GroupKeyIndex(){ 
    }

//forbidden copy constructe function
private:
    GroupKeyIndex(const GroupKeyIndex<T>&);
    GroupKeyIndex<T>& operator=(const GroupKeyIndex<T>&);
    
private:
    int mergeProcess(){}

private:
    //main data structure
    vector_ptr_t m_IndexVector;
    vector_ptr_t m_PositionVector;
    vector_ptr_t m_AttributeVector;
    dic_ptr_t m_Dictionary;

    DeltaData m_CDeltaData;
};
#endif

