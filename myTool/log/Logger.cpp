/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified:	2014-05-07 10:25
#
# Filename:		Logger.cpp
#
# Description: 
#
=============================================================================*/
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "Logger.h"
#include "Error.h"

const char* LOG_FILE_NAME = "logger";
const int MAX_SIZE = 256;
const int BUFFER_SIZE_LOG_FILE = 4096;

Logger* Logger::m_pLog = NULL;
pthread_once_t Logger::m_once = PTHREAD_ONCE_INIT;

Logger::Logger(){
    m_iFd = ::open( LOG_FILE_NAME, O_RDWR | O_CREAT 
            | O_APPEND , S_IRUSR | S_IWUSR );
    
    m_pLogBuffer = new char[ BUFFER_SIZE_LOG_FILE ];
    m_nUsedBytesForBuffer = 0;

    m_bFlagForProcessExit = false;
}

Logger::~Logger(){
    delete[] m_pLogBuffer;

    if( m_iFd > 0){
        close(m_iFd);
    }
}

void Logger::createSingleLogger(){
    m_pLog = new Logger();
}

Logger* Logger::getInstance(){
    if( m_pLog == NULL ){
        pthread_once(&m_once,createSingleLogger);

        if( 0 != atexit(Logger::onProcessExit) ){
            if( m_pLog != 0 ){
                m_pLog->m_bFlagForProcessExit = true;
                m_pLog->writeLog("In Logger::getInstance(), atexit error",errno);
            }            
        }

        if( SIG_ERR == signal(SIGINT , Logger::handleSigInt ) ){
            if( m_pLog != 0){
                m_pLog->m_bFlagForProcessExit = true;
                m_pLog->writeLog("In Logger::getInstance(), signo error",errno);
            }
        }
    }

    return m_pLog;
}

int Logger::writeLog(const char* pLogMessage,long lErrorCode){
    if( NULL == pLogMessage ) 
        return FAILED;
    
    if( 0 == ::strlen(pLogMessage) )
        return FAILED;

    if( NULL == m_pLogBuffer )
        return FAILED;

    unsigned int nLeftRoom = BUFFER_SIZE_LOG_FILE - m_nUsedBytesForBuffer;

    unsigned int nLogMessageLen = ::strlen( pLogMessage );

    char buf[MAX_SIZE];

    ::snprintf(buf , MAX_SIZE ,"  ErrorCode:%ld\n", lErrorCode);

    unsigned int nCodeLen = ::strlen( buf );
    
    unsigned int nTotalLen = nCodeLen + nLogMessageLen;
    
    if((nTotalLen > BUFFER_SIZE_LOG_FILE ) || (m_bFlagForProcessExit)){
        if( -1 == m_iFd )
            return FAILED;

        ssize_t r = write( m_iFd, pLogMessage, nLogMessageLen);
        if( -1 == r )
           return FAILED;

        r = write(m_iFd, buf , nCodeLen );
        if( -1 == r )
            return FAILED;

        return SUCCESSFUL;
    }

    if( nTotalLen > nLeftRoom ){
        int s = flush();
        if( FAILED == s)
            return FAILED;
    }

    memcpy(m_pLogBuffer+m_nUsedBytesForBuffer, pLogMessage , nLogMessageLen );

    m_nUsedBytesForBuffer += nLogMessageLen;

    memcpy(m_pLogBuffer + m_nUsedBytesForBuffer, buf, nCodeLen );

    m_nUsedBytesForBuffer += nCodeLen;

    return SUCCESSFUL;
}

int Logger::writeLogMessage( const char* pLogMessage,
                             long lErrorCode ){
   Logger* pLogger = Logger::getInstance(); 
   if( NULL == pLogger ){
        return FAILED;
   }

   return pLogger->writeLog(pLogMessage, lErrorCode);
}

int Logger::flush(){
    if(-1 == m_iFd )
        return FAILED;

    if( NULL == m_pLogBuffer )
        return FAILED;

    if( 0 == m_nUsedBytesForBuffer )
        return SUCCESSFUL;

    ssize_t r = write( m_iFd, m_pLogBuffer , m_nUsedBytesForBuffer );
    if( -1 == r )
       return FAILED;

    m_nUsedBytesForBuffer = 0;
    return SUCCESSFUL; 
}

void Logger::onProcessExit( void ){
    Logger* pLogger = Logger::getInstance();
    if( NULL != pLogger ){
        pLogger -> flush();
        pLogger -> m_bFlagForProcessExit = true;
    }
}

void Logger::handleSigInt( int signo){
    if( SIGINT == signo ){
        printf("handle SIGINT! \n");
        exit(1);
    } 
}

