/*
 * =================================================================
 *
 *            Filename:    ThreadPoolDispatcher.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-14 21:37
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef THREADPOOLDISPATCHER_H_
#define THREADPOOLDISPATCHER_H_
#include "ThreadPool.h"
#include "ThreadWorkItem.h"
#include "Channel.h"
#include <vector>

class ThreadPool;
class ThreadWorkItem;
class ThreadPoolDispatcher{
public:
    ThreadPoolDispatcher(ThreadPool *pThreadPool,const char *ChannelName);
    virtual ~ThreadPoolDispatcher();

    int initial( int threadNumber );
    int sendTask( ThreadWorkItem* );
    int reciveTask();
    
    int getWriteBackFd();

private:
    ThreadPool *m_pThreadPool;
    Channel *m_pChannel;
    std::vector< int > m_ThreadWriteFdList;
    int m_ThreadNumber;
    int m_Cursor;
};

#endif
