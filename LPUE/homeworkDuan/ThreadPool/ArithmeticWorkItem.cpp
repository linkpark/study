/*
 * =================================================================
 *
 *            Filename:    ArithmeticWorkItem.cpp
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-16 14:09
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#include "ArithmeticWorkItem.h"
#include "Error.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

ArithmeticWorkItem::ArithmeticWorkItem(int writeBackFd,int opOne, int opTwo, int opType):
    m_WriteBackFd(writeBackFd),m_OpOne(opOne),m_OpTwo(opTwo),m_OpType(opType){

}

ArithmeticWorkItem::~ArithmeticWorkItem(){

}

int ArithmeticWorkItem::beforeProcess(){
    return SUCCESSFUL;
}

int ArithmeticWorkItem::process(){
    switch(m_OpType){
        case ADD:
            m_Result = m_OpOne + m_OpTwo;
            m_State = SUCCESSFUL;
            break;
        case SUB:
            m_Result = m_OpOne - m_OpTwo;
            m_State = SUCCESSFUL;
            break;
        case MUTIP:
            m_Result = m_OpOne * m_OpTwo;
            m_State = SUCCESSFUL;
            break;
        case DIV:
            if( m_OpTwo == 0){
                perror("div zero !\n");
                m_State = FAILED;
                m_Result = -1;
                break;
            }
            m_Result = m_OpOne / m_OpTwo;
            break;
    } 

    return SUCCESSFUL;
}

int ArithmeticWorkItem::postProcess(){
    struct ResultStruct result;
    int r;

    result.workId = this->getTaskID();
    result.result = m_Result;
    result.state = SUCCESSFUL;

    if( (r = write(m_WriteBackFd, &result, sizeof(result)) ) < 0){
        perror("In ArithmeticWorkItem::postProcess() write error!\n");
        return FAILED;
    }

    return SUCCESSFUL;   
};

