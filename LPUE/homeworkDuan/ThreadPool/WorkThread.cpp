/*
 * =================================================================
 *
 *            Filename:    WorkThread.cpp
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-14 19:17
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#include "WorkThread.h"
#include "Error.h"
#include "FIFOChannel.h"

#include <stdio.h>
#include <unistd.h>

WorkThread::WorkThread():Thread(), m_WriteBackFd( -1 ){
    m_WorkThreadChannel = NULL;
    m_pThreadWorkItem = NULL;
}

WorkThread::~WorkThread(){
}

int WorkThread::runThreadFunction(){
    int n;
    int readFd = m_WorkThreadChannel->getReadFd();

    while( (n = read( readFd, &m_pThreadWorkItem , sizeof( m_pThreadWorkItem )) ) > 0){
        m_pThreadWorkItem->beforeProcess();
        m_pThreadWorkItem->process();
        m_pThreadWorkItem->postProcess();
    }

    delete m_pThreadWorkItem;
    m_pThreadWorkItem = NULL;

    if( n < 0 ){
        perror("in WorkThread::runThreadFunction() read error!\n");
        return FAILED;
    }

    return SUCCESSFUL;
}

int WorkThread::initial( int fifoNumber ){
    char pathName[20];
    sprintf(pathName, "%d.fifo", fifoNumber);

    m_WorkThreadChannel = new FIFOChannel(pathName);
    
    if( m_WorkThreadChannel->initial() < 0 ){
        perror("In WorkThread::initial() m_WorkThreadChannel initial() error!\n");
        return FAILED;
    }
     
    return SUCCESSFUL;
}

int WorkThread::getChannelWriteFd(){
    if(m_WorkThreadChannel == NULL){
        perror("In WorkThread::getChannelWriteFd() no initial of Channel\n");
        return FAILED;
    }

    return m_WorkThreadChannel->getWriteFd();
}


