/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified:	2014-05-06 16:57
#
# Filename:		Logger.h
#
# Description: 
#
=============================================================================*/
#ifndef LOGGER_H
#define LOGGER_H

#include "Error.h"
#include <pthread.h>
class Logger{
public:
    static Logger* getInstance( void );
    static int writeLogMessage( const char* pLogMessage, 
                                long lErrorCode );

    int writeLog( const char* pLogMessage, 
                    long lErrorCode);

    int flush( void );

private:
    static void onProcessExit( void );
    static void handleSigInt( int signo );
    static void createSingleLogger(void);

private:
    Logger(const Logger&);
    Logger& operator=( const Logger& );

    Logger();
    ~Logger();

private:
    int m_iFd;
    static Logger* m_pLog;

private:
    char *m_pLogBuffer;
    unsigned int m_nUsedBytesForBuffer;

private:
    bool m_bFlagForProcessExit;
    static pthread_once_t m_once;
};

#endif 
