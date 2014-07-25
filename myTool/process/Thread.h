/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-17 14:16
#
# Filename: Thread.h
#
# Description: 
#
=============================================================================*/
#ifndef THREAD_H_
#define THREAD_H_
#include "Executive.h"
#include "ExecutiveFuncProvider.h"
#include <pthread.h>
#include <sys/types.h>

class Thread:public Executive{
public:
    explicit Thread(ExecutiveFuncProvider *pFuncProvider);
    virtual ~Thread();
    
    virtual int run(void *pContext = NULL);
    virtual int waitForDeath();

//edit the thread attribute
public:
    int threadAttrInit();
    int threadAttrDestroy();

    int setDetachState();
    int setStackSize( size_t stackSize );

private:
    static void* startFuncOfThread(void *pContext);

private:
    void *m_pContext;
    pthread_t m_ThreadId;
    bool m_bThreadCreated;
    pthread_attr_t *m_pThreadAttr;
};

#endif

