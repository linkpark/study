/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-17 14:16
#
# Filename: Thread.cpp
#
# Description: 
#
=============================================================================*/
#include "Thread.h"
#include "Logger.h"
#include "Error.h"
#include <errno.h>

Thread::Thread(ExecutiveFuncProvider *pFuncProvider):
                Executive(pFuncProvider){
    m_pContext = NULL;
    m_bThreadCreated = false;
    m_pThreadAttr = NULL;
}

Thread::~Thread(){
}

int Thread::run( void *pContext ){
    if(m_bThreadCreated)
        return FAILED;

    m_pContext = pContext;

    int r = pthread_create( &m_ThreadId, m_pThreadAttr,
            startFuncOfThread, this);
    if( 0 != r ){
        Logger::writeLogMessage("In Thread::run() \
                pthread_create error!", errno);
        return FAILED; 
    }
    
    m_bThreadCreated = true;
    return SUCCESSFUL;
}

int Thread::waitForDeath(){
    if( !m_bThreadCreated )
        return FAILED;

    int r = pthread_join( m_ThreadId, 0);

    if( 0 != r ){
        if(EINVAL == r )
            Logger::writeLogMessage("In Thread::waitForDeath() \
                    thread detached!",errno); 
        else
            Logger::writeLogMessage("In Thread::waitForDeath() \
                    pthread_join error!",errno);

        return FAILED;
    }    

    return SUCCESSFUL;
}

void* Thread::startFuncOfThread(void *pContext){
    Thread *pThreadThis = static_cast< Thread* >( pContext );

    pThreadThis->getExecutiveFuncHandler() \
        ->runExecutiveFunc( pThreadThis->m_pContext );

    return NULL;
}

int Thread::threadAttrInit(){
    m_pThreadAttr = new pthread_attr_t();
    
    if( 0 != pthread_attr_init( m_pThreadAttr ) ){
        Logger::writeLogMessage("Thread::threadAttrInit() \
                pthread_attr_init error!",errno);
        return FAILED;
    }

    return SUCCESSFUL;
}

int Thread::threadAttrDestroy(){
    if( NULL != m_pThreadAttr ){
        if( 0 != pthread_attr_destroy( m_pThreadAttr ) ){
            Logger::writeLogMessage("Thread::threadAttrDestroy() \
                    pthread_attr_destroy error!",errno);
            return FAILED;
        }
        delete m_pThreadAttr;
        m_pThreadAttr = NULL;
    }

    return SUCCESSFUL;    
}

int Thread::setDetachState(){
    if( NULL == m_pThreadAttr ){
        Logger::writeLogMessage( "Thread::setDetachState()\
                m_pThreadAttr should init first!",errno );
        return FAILED;    
    }

    if( 0 != pthread_attr_setdetachstate(m_pThreadAttr,PTHREAD_CREATE_DETACHED) ){
        Logger::writeLogMessage( "Thread::setDetachState()\
                pthread_attr_setdetachstate error!",errno );
        return FAILED;
    }

    return SUCCESSFUL;    
}

//stackSize can't less than PTHREAD_STACK_MIN 
int Thread::setStackSize( size_t stackSize ){
    if( NULL == m_pThreadAttr ){
        Logger::writeLogMessage( "Thread::setStackSize()\
                m_pThreadAttr should init first!",errno );
        return FAILED;     
    }

    if( 0 != pthread_attr_setstacksize( m_pThreadAttr,stackSize ) ){
        Logger::writeLogMessage( "Thread::setStackSize()\
                pthread_attr_setstacksize error!",errno );
        return FAILED;
        
    }

    return SUCCESSFUL;
}

