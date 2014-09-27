#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#include "FileOperator.h"

using namespace std;

FileOperator::FileOperator(int bufSize):m_iBufSize(bufSize){
    if(bufSize <= 0){
        m_iBufSize = 0;
        m_pBuf = nullptr;
    }else{
        m_pBuf = new char[m_iBufSize];
    }
}

FileOperator::FileOperator():m_iBufSize(DEFAULTBUFSIZE){
    m_pBuf = new char[m_iBufSize];
}



