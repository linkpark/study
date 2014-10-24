/*
 * =================================================================
 *
 *            Filename:    Agent.h
 *
 *         Description:    
 *
 *             Version:    
 *             Created:    2014-10-24 13:26
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef AGENT_H_
#define AGENT_H_
#include <sys/types.h>
#include "Task.h"

class Task;
class Agent{
protected:
    int m_iFd;
    Task *m_pTask;    

public:
    Agent():m_iFd(-1){}
    Agent(Task *pTask):m_iFd(-1),m_pTask(pTask){}
    virtual ~Agent(){}

public:
    virtual int readData( void ) = 0;
    virtual int writeData(void ) = 0; 
};

#endif
