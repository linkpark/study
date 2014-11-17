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
#include <stdio.h>

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
        if( pWorkThread->initial( i ) < 0 ){
            perror("In ThreadPool::initial() pWorkThread->initial error!\n");
            return FAILED;
        }

        pWorkThread->run( NULL );
        m_ThreadList[ pWorkThread ] = true;
    }
    
    return SUCCESSFUL;
}

std::vector< int > ThreadPool::applyForThreads( int threadNumber){
    if( threadNumber > m_FreeThreadNumber )
        throw "Don't have enough free list\n";

    int count = 0 ;
    std::vector< int > writeFdList;
    std::map< WorkThread*, bool >::iterator mapIt;

    for( mapIt = m_ThreadList.begin() ; mapIt != m_ThreadList.end() ; ++mapIt){
        if(mapIt->second){
            writeFdList.push_back( mapIt->first->getChannelWriteFd() );
            mapIt->second = false;
            count ++;
        }

        if( count == threadNumber )
            break;
    }        

    return writeFdList;
}

