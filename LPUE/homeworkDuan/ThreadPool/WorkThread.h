/*
 * =================================================================
 *
 *            Filename:    WorkThread.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-14 19:05
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef WORKTHREAD_H_
#define WORKTHREAD_H_
#include "Thread.h"
#include "Channel.h"
#include "ThreadWorkItem.h"

class ThreadWorkItem;
class WorkThread : public Thread{
public:
    WorkThread();
    ~WorkThread();

    int runThreadFunction( void ); 
    int initial( int );
    int getChannelWriteFd();

private:
    Channel *m_WorkThreadChannel;
    ThreadWorkItem *m_pThreadWorkItem; 
    int m_WriteBackFd;
};

#endif
