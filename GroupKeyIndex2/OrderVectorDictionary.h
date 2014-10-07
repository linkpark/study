/*
 * =================================================================
 *
 *            Filename:    OrderVectorDictionary.h
 *
 *         Description:    an ordered dictionary using vector to store 
 *
 *             Version:    v1.0
 *             Created:    2014-10-05 15:48
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef ORDERVECTORDICTIONARY_H_
#define ORDERVECTORDICTIONARY_H_
#include <vector>
#include "BaseDictionary.h"

template<class T>
class OrderVectorDictionary:public BaseDictionary<T>{
private:
    typedef std::vector<T> vector_type;

public:
    OrderVectorDictionary(){}
    ~OrderVectorDictionary(){}

public:
    value_id_t constructDictionaryByVector(std::vector<T> &originData);
    value_id_t addValue( T &value );
    
    T getValueByValueId( value_id_t valueId);
    value_id_t findValueIdForValue( T &value );
    
    const T getSmallestValue();
    const T getGreatestValue();
    
    bool isValueExists( value_id_t valueId );
    bool isOrderd(); 

private:
    vector_type m_Values;
};
#endif
