#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <error.h>

#include "Logger.h"
#include "Error.h"
#include "FileOperator.h"

using namespace std;

FileOperator::FileOperator()
    :m_iBufSize(0),m_iUsedBufSize(0),m_pWriteBuf(nullptr),m_pReadBuf(nullptr),m_iFileFd(-1),m_iFileOffset(0){
}

FileOperator::~FileOperator(){
}


int FileOperator::initial(int bufSize){
    if(bufSize <= 0){
        Logger::getInstance()->writeLogMessage("FileOperator::initial bufSize can't be nagative\n",-1);
        return FAILED;
    }else{
        m_iBufSize = bufSize;
        m_pWriteBuf = new char[m_iBufSize];
    }

    return SUCCESSFUL; 
}

void FileOperator::destory(){
    if(nullptr != m_pWriteBuf )
        delete []m_pWriteBuf;

    if( nullptr != m_pReadBuf )
        delete []m_pReadBuf;
}

int FileOperator::fileOpen(const char *path,int flags,mode_t mode){
    m_iFileFd = open( path,flags,mode );
    if( m_iFileFd < 0 ){
        Logger::getInstance()->writeLogMessage("FileOperator::open open error!\n",errno);
        return FAILED;
    } 

    return SUCCESSFUL;
}

int FileOperator::fileRead(void *buf,size_t count){
    if( m_iFileFd < 0 ){
        Logger::getInstance()->writeLogMessage("FileOperator::fileRead open first!\n",-1);
        return FAILED;
    }
}

