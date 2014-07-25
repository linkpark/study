/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-30 16:15
#
# Filename: Mutex.cpp
#
# Description: 
#
=============================================================================*/
#include "Mutex.h"
#include "Error.h"
#include "Logger.h"
#include <errno.h>

Mutex::Mutex(){
}

Mutex::~Mutex(){
}

int Mutex::initLock(){
    int r = pthread_mutex_init( &m_Mutex, 0 );
    if( 0 != r ){
        Logger::writeLogMessage("In Mutex::initLock \
                pthread_mutex_init error!",errno);
        return FAILED;
    }

    return SUCCESSFUL;
}

int Mutex::destoryLock(){
    int r = pthread_mutex_destroy( &m_Mutex );
    if( 0 != r ){
        Logger::writeLogMessage( "In Mutex::destoryLock \
                pthread_mutex_destroy error!" ,errno );
        return FAILED;
    }

    return SUCCESSFUL;
}

int Mutex::lock(){
    int r = pthread_mutex_lock( &m_Mutex );
    if( 0 != r ){
        Logger::writeLogMessage( "In Mutex::lock \
                phtread_mutex_lock error!",errno );
        return FAILED;
    }   

    return SUCCESSFUL; 
}

int Mutex::unLock(){
    int r = pthread_mutex_unlock( &m_Mutex );
    if( 0 != r ){
        Logger::writeLogMessage( "In Mutex::unLock \
                pthread_mutex_unlock error!", errno );
        return FAILED;
    }

    return SUCCESSFUL;
}

pthread_mutex_t Mutex::getMutex()const{
    return m_Mutex; 
}
