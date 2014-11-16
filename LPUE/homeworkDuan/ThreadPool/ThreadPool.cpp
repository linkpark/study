/*
 * =================================================================
 *
 *            Filename:    ThreadPool.cpp
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-16 18:32
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#include "ThreadPool.h"
#include "Error.h"

ThreadPool::ThreadPool():m_TotalThreadNumber(0),m_FreeThreadNumber(0){
}

ThreadPool::~ThreadPool(){
}

int ThreadPool::initial( int threadNumber ){
    m_TotalThreadNumber = threadNumber;
    m_FreeThreadNumber = threadNumber;
    WorkThread* pWorkThread;
    int i;

    for( i = 0 ; i < threadNumber ; i++){
        pWorkThread = new WorkThread();
        pWorkThread->initial( i );
    }


    return SUCCESSFUL;
}

std::vector< int > applyForThreads( int threadNumber){

}

