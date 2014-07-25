/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-06-04 14:43
#
# Filename: CriticalSection.cpp
#
# Description: 
#
=============================================================================*/
#include "CriticalSection.h"
#include "Logger.h"
#include "Error.h"
#include <errno.h>

CriticalSection::CriticalSection(Mutex *pMutex){
    if( NULL == pMutex ){
        Logger::writeLogMessage ("In CriticalSection:: \
                CriticalSection(),pMutex == NULL" , errno );
        throw "In CriticalSection::CriticalSection(),pMutex == NULL";   
    } 

    m_pMutex = pMutex;

    int r = m_pMutex->lock();
    if( FAILED == r ){
        Logger::writeLogMessage( "In CriticalSection::CriticalSection(),\
                m_pMutex->lock error!", errno);
        throw "In CriticalSection::CriticalSection(), m_pMutex->lock() error!"; 
    } 
}

CriticalSection::~CriticalSection(){
    int r = m_pMutex->unLock();
    if( FAILED == r ){
        Logger::writeLogMessage ( "In CriticalSection::CriticalSection(),\
                m_pMutex->unLock() error!" , errno);
    }
}

