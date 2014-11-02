/*
 * =================================================================
 *
 *            Filename:    EchoTask.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-01 19:42
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef ECHOTASK_H_
#define ECHOTASK_H_
#include "Task.h"

class EchoTask:public Task{
public:
    int readTask( void *pContext );
    int writeTask( void *pContext );
};

#endif
