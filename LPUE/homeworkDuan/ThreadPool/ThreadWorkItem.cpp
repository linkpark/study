/*
 * =================================================================
 *
 *            Filename:    ThreadWorkItem.cpp
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-14 19:56
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#include "ThreadWorkItem.h"
#include "Error.h"

ThreadWorkItem::ThreadWorkItem(){

}

ThreadWorkItem::~ThreadWorkItem(){

}

int ThreadWorkItem::beforeProcess(){
    return SUCCESSFUL;
}

void ThreadWorkItem::setTaskID( uint64_t taskID){
    m_taskID = taskID;
}

uint64_t ThreadWorkItem::getTaskID()const{
    return m_taskID;
}


