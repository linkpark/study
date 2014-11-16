/*
 * =================================================================
 *
 *            Filename:    ThreadPool.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-16 17:25
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include "WorkThread.h"
#include <map>
#include <vector>

class ThreadPool{
public:
    ThreadPool();
    virtual ~ThreadPool();

public:
    int initial( int threadNumber );   
    std::vector<int> applyForThreads( int threadNumber );

private:
    std::map< WorkThread*, bool > m_ThreadList;
    int m_ThreadNumber;
};

#endif
