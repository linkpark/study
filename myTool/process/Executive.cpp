/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-17 14:17
#
# Filename: Executive.cpp
#
# Description: 
#
=============================================================================*/
#include "Executive.h"
#include "ExecutiveFuncProvider.h"

Executive::Executive( ExecutiveFuncProvider *pFuncProvider ){
    if( 0 == pFuncProvider )
        throw "In Executive::Executive(), ExecutiveFuncProvider error!";

    m_pExecutiveFuncProvider = pFuncProvider;
}

Executive::~Executive(){
}

ExecutiveFuncProvider* Executive::getExecutiveFuncHandler()const{
    return m_pExecutiveFuncProvider;
}

