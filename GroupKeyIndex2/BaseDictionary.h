/*
 * =================================================================
 *
 *            Filename:    DictionaryBase.h
 *
 *         Description:    dictinary base class 
 *
 *             Version:    v1.0
 *             Created:    2014-10-05 14:56
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef BASEDICTIONARY_H_
#define BASEDICTIONARY_H_
#include <sys/types.h>
#include <stdexcept>
#include "types.h"

template<class T>
class BaseDictionary{
public:
    virtual ~BaseDictionary(){}

    virtual value_id_t addValue( T &value ) = 0; 
    virtual T getValueByValueId( value_id_t valueId ) = 0;
    virtual value_id_t findValueIdForValue( T &value ) = 0;

    virtual const T getSmallestValue() = 0;
    virtual const T getGreatestValue() = 0;
    
    virtual bool isValueExists( value_id_t valueId ) = 0;
    virtual bool isOrdered() = 0;
};

#endif
