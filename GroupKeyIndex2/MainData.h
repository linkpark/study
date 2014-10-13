#ifndef MAINDATA_H_
#define MAINDATA_H_
#include <vector>
#include <map>
#include <memory>
#include <exception>

#include "BitCompressedVector.h"
#include "BaseDictionary.h"
#include "OrderVectorDictionary.h"

template< class T >
class MainData{
private:
    typedef OrderVectorDictionary<T> dic_t;
    typedef BitCompressedVector<T> vector_t;
    typedef std::shared_ptr<vector_t> vector_ptr_t;
    typedef std::shared_ptr<dic_t> dic_ptr_t; 

public:
    MainData(){
        m_Dictionary = std::make_shared< dic_t >(); 
        m_PositionVector = std::make_shared< vector_t >();
        m_IndexVector = std::make_shared< vector_t >();
        m_AttributeVector = std::make_shared< vector_t >();
    };

    ~MainData(){};

    void importOriginData(std::vector<T> &originData){
        value_id_t dicNumber;
        dicNumber = m_Dictionary -> constructDictionaryByVector( originData );

        if(dicNumber == 0)
            throw std::logic_error("empty dictionary");
    }

    dic_ptr_t getDictionaryPtr()const{
        return m_Dictionary;
    } 
   
    vector_ptr_t getPositionVector()const{
        return m_PositionVector;
    }

    vector_ptr_t getIndexVector()const{
        return m_IndexVector;
    }

    vector_ptr_t getAttributeVector()const{
        return m_AttributeVector;
    }


private:
    vector_ptr_t m_IndexVector;
    vector_ptr_t m_PositionVector;
    vector_ptr_t m_AttributeVector;
    dic_ptr_t m_Dictionary;
};

#endif
