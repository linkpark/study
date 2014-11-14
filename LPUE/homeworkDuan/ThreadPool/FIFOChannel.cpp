#include "FIFOChannel.h"
#include "Error.h"
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

FIFOChannel::FIFOChannel(const char* fifoName):Channel(),m_FIFOName(fifoName){
    m_bIsInitial = false;
}

FIFOChannel::~FIFOChannel(){

}

int FIFOChannel::getReadFd(){
    if( !m_bIsInitial ){
        perror("In FIFOChannel::getReadFd initial first\n");
        return FAILED;
    }

    if( m_ReadFd == -1){
        m_ReadFd = open( m_FIFOName.c_str(), O_RDONLY, 0 );
    }

    return m_ReadFd;
}

int FIFOChannel::getWriteFd(){
    if( !m_bIsInitial ){
        perror("In FIFOChannel::getWriteFd initial first\n");
        return FAILED;
    }

    if( m_WriteFd == -1){
        m_WriteFd = open( m_FIFOName.c_str(), O_WRONLY , 0 );
    }

    return m_WriteFd;
}

int FIFOChannel::initial(){
    if((mkfifo(m_FIFOName.c_str() , FILE_MODE ) < 0) && (errno != EEXIST) ){
        perror("In FIFOChannel::initial() mkfifo error!\n");
        return FAILED;
    }
    
    m_bIsInitial = true;

    return SUCCESSFUL;
}

