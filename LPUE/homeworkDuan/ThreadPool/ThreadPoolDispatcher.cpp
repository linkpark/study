/*
 * =================================================================
 *
 *            Filename:    ThreadPoolDispatcher.cpp
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-14 22:00
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#include "ThreadPoolDispatcher.h"
#include "FIFOChannel.h"
#include "Error.h"
#include "ArithmeticWorkItem.h"
#include <unistd.h>
#include <iostream>
#include <stdio.h>

ThreadPoolDispatcher::ThreadPoolDispatcher( ThreadPool *pThreadPool, 
        const char *pChannelName ):m_pThreadPool(pThreadPool),m_pChannel(NULL){ 
    m_ThreadNumber = 0;
    m_Cursor = 0;

    m_pChannel = new FIFOChannel( pChannelName);
    if( m_pChannel->initial() < 0){
        throw "In ThreadPoolDispatcher::initial FIFO error!\n";
    }
}

ThreadPoolDispatcher::~ThreadPoolDispatcher(){
    delete m_pChannel;
}

int ThreadPoolDispatcher::initial( int threadNumber){
    if( m_pChannel->initial() < 0 ){
        perror("In ThreadPoolDispatcher::initial() error!\n");
        return FAILED;
    }
    
    m_ThreadWriteFdList = m_pThreadPool->applyForThreads( threadNumber );    
    m_ThreadNumber = threadNumber;

    return SUCCESSFUL;
}

int ThreadPoolDispatcher::sendTask( ThreadWorkItem *pWorkItem ){    
    int writeFd = m_ThreadWriteFdList[ m_Cursor ];
    int r;

    if( (r = write(writeFd, &pWorkItem , sizeof(pWorkItem)) ) < 0 ){
        perror("In ThreadPoolDispatcher::sendTask() write error!\n");
        return FAILED; 
    }

    m_Cursor = ( m_Cursor + 1 ) % m_ThreadNumber;

    return SUCCESSFUL;
}

int ThreadPoolDispatcher::reciveTask(){
    struct ResultStruct result;
    int readFd = m_pChannel -> getReadFd();
    int r;

    do{
        r = read( readFd , &result , sizeof( result ));
        if( SUCCESSFUL == result.state )
            std::cout << "WorkNumber:" << result.workId << " result:" <<result.result <<std::endl; 
        else
           std::cout << "Operator error!" << std::endl;
    }while( r > 0 );

    if( r < 0 ){
        perror("In ThreadPoolDispatcher::reciveTask() read error!\n");
        return FAILED;
    }

    return SUCCESSFUL;
}

int ThreadPoolDispatcher::getWriteBackFd(){
    return m_pChannel->getWriteFd();
}

