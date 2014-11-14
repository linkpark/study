/*
 * =================================================================
 *
 *            Filename:    Thread.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-14 15:06
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef THREAD_H_
#define THREAD_H_
#include <pthread.h>
class Thread{
public:
    Thread();
    virtual ~Thread();

    int run( void *pContext );
    int waitForDeath( void ); 

private:
    static void *startFunctionOfThread(void *pContext);

protected:
    virtual int runThreadFunction( void ) = 0;

protected:
    void *m_pContext;
    pthread_t m_ThreadID;

};
#endif
