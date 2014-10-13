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
#include <set>
#include "BaseDictionary.h"

template<class T>
class OrderVectorDictionary:public BaseDictionary<T>{
private:
    typedef std::vector<T> vector_type;

public:
    OrderVectorDictionary(){}
    ~OrderVectorDictionary(){}

public:
    value_id_t constructDictionaryByVector(std::vector<T> &originData){
        std::set<T> setsOfValue;

        for(typename std::vector<T>::iterator ix = originData.begin(); ix != originData.end() ; ++ix){
            setsOfValue.insert( *ix );    
        }

        for(typename std::set<T>::iterator ix = setsOfValue.begin();ix != setsOfValue.end(); ++ix){
            m_Values.push_back( *ix );
        }

        return m_Values.size();
    }

    value_id_t addValue( T &value ){
        if( (m_Values.size()) > 0 && (value <= m_Values.back()) ){
            throw std::runtime_error("can't insert smaller or equal than last value!");
        }

        m_Values.push_back(value);
        return m_Values().size() - 1;
    }
    
    T getValueByValueId( value_id_t valueId){
        if( valueId > m_Values.size() ){
           throw std::overflow_error("the value id is over flow!");
        }
    
        return m_Values[valueId]; 
    }

    value_id_t findValueIdForValue( T &value ){
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
    
    const T getSmallestValue(){
        typename vector_type::iterator it;
        it = m_Values.begin();

        return *it;        
    }

    const T getGreatestValue(){
        typename vector_type::iterator it;
        it = m_Values.end();

        return *it;
    }
    
    bool isValueExists( value_id_t valueId ){
        if( valueId > m_Values.size() ){
            return false;
        }else{
            return true;
        }
    }

    bool isOrderd(){
        return true;
    }

private:
    vector_type m_Values;
};
#endif
