/*
 * =================================================================
 *
 *            Filename:    OrderVectorDictionary.cpp
 *
 *         Description:    the implement of Orderded vector dictionary
 *
 *             Version:    v1.0
 *             Created:    2014-10-06 18:39
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */

#include <iostream>
#include <set>
#include "OrderVectorDictionary.h"

template<class T>
value_id_t OrderVectorDictionary<T>::constructDictionaryByVector( std::vector<T> &originData ){
    std::set<T> setsOfValue;

    for(typename std::vector<T>::iterator ix = originData.begin(); ix != originData.end() ; ++ix){
        setsOfValue.insert( *ix );    
    }

    for(typename std::set<T>::iterator ix = setsOfValue.begin();ix != setsOfValue.end(); ++ix){
        m_Values.push_back( *ix );
    }

    return m_Values.size();
}

/*****************************************
 *   FunctionName:addValue  
 *    Description:this function can only 
 *              insert the biggest value or it
 *              may throw error
 *         Return:the value id of the insert 
 *              element.
 *****************************************/
template<class T>
value_id_t OrderVectorDictionary<T>::addValue( T &value ){
    if( (m_Values.size()) > 0 && (value <= m_Values.back()) ){
        throw std::runtime_error("can't insert smaller or equal than last value!");
    }

    m_Values.push_back(value);
    return m_Values().size() - 1;
}

template<class T>
T OrderVectorDictionary<T>::getValueByValueId( value_id_t valueId ){
    if( valueId > m_Values.size() ){
        throw std::overflow_error("the value id is over flow!");
    }
    
    return m_Values[valueId];
}

template<class T>
value_id_t OrderVectorDictionary<T>::findValueIdForValue( T &value ){
    value_id_t lowerBound = 0;
    value_id_t highBound = m_Values.size() - 1;
    value_id_t middle = 0;

    while(lowerBound <= highBound){
        middle = ( lowerBound + highBound ) / 2;
        
        if( m_Values[middle] < value ){
            lowerBound = middle + 1;    
        }else if( m_Values[middle] > value ){
            highBound = middle - 1;
        }else{
            return middle;
        }
    }
    
    throw std::runtime_error("can't find the element");    
}

template<class T>
const T OrderVectorDictionary<T>::getSmallestValue(){
    typename vector_type::iterator it;
    it = m_Values.begin();

    return *it;
}

template<class T>
const T OrderVectorDictionary<T>::getGreatestValue(){
    typename vector_type::iterator it;
    it = m_Values.end();

    return *it;
}

template<class T>
bool OrderVectorDictionary<T>::isValueExists(value_id_t valueId){
    if( valueId > m_Values.size() ){
        return false;
    }else{
        return true;
    }
}

template<class T>
bool OrderVectorDictionary<T>::isOrderd(){
    return true;
}

