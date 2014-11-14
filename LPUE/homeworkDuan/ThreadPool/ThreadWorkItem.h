/*
 * =================================================================
 *
 *            Filename:    ThreadWorkItem.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-14 19:50
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef THREADWORKITEM_H_
#define THREADWORKITEM_H_
#include <stdint.h>

class ThreadWorkItem{
public:
    ThreadWorkItem();
    virtual ~ThreadWorkItem();

public:
    virtual int beforeProcess();
    virtual int process() = 0;
    virtual int postProcess() = 0;    

    void setTaskID( uint64_t taskID);
    uint64_t getTaskID()const;

private:
    uint64_t m_taskID;
};

#endif
