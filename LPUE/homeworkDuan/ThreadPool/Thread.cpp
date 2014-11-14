/*
 * =================================================================
 *
 *            Filename:    Thread.cpp
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-14 16:17
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#include "Thread.h"
#include "Error.h"
#include <stdio.h>

Thread::Thread(){
    m_pContext = NULL;
}

Thread::~Thread(){
}

int Thread::run( void *pContext ){
    m_pContext = pContext;

    int r = pthread_create(&m_ThreadID, NULL, startFunctionOfThread , this);
    if( r < 0){
        perror("in Thread:: run pthread_create error!\n");
        return FAILED;
    }
    
    return SUCCESSFUL;    
}

int Thread::waitForDeath(){
    int r = pthread_join(m_ThreadID , NULL );
    if( r != 0){
        perror("in Thread:: waitForDeath pthread_join error!\n");
    }

    return SUCCESSFUL;
}

void* Thread::startFunctionOfThread(void *pContext){
    Thread *pThis = (Thread *)pContext;
    int *r = new int;

    *r = pThis->runThreadFunction();

    return (void*)r;
} 


