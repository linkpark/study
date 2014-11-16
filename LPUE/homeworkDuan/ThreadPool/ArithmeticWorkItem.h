/*
 * =================================================================
 *
 *            Filename:    ArithmeticWorkItem.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-16 13:53
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef ARITHMETICWORKITEM_H_
#define ARITHMETICWORKITEM_H_

#include "ThreadWorkItem.h"

const int ADD = 0;
const int SUB = 1;
const int MUTIP = 2;
const int DIV = 3;

struct ResultStruct{
    int result;
    int state;
    uint64_t workId;
};

class ArithmeticWorkItem: public ThreadWorkItem{    
public:
    ArithmeticWorkItem(int writeBackFd,int opOne, int opTwo, int opType);
    ~ArithmeticWorkItem();

public:
    int beforeProcess();
    int process();
    int postProcess();

private:
    inline void addOperation();
    inline void subOperation();
    inline void mutiplyOperation();
    inline void divisionOperation();

private:
    int m_WriteBackFd;
    int m_OperationType;
    int m_OpOne;
    int m_OpTwo;
    int m_OpType;
    int m_Result;
};

#endif
