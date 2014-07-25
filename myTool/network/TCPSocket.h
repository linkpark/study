/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-07 20:22
#
# Filename: TCPSocket.h
#
# Description: 
#
=============================================================================*/
#ifndef TCPSOCKET_H_
#define TCPSOCKET_H_
#include <sys/uio.h>

class TCPSocket{
public:
    TCPSocket();
    TCPSocket( int iFd );
    ~TCPSocket();

public:
    int createSocket( void );
    int bind();
    int listen( int iQueryLen );
    int connect();
    int accept();
    int read( char *pBuf,size_t sLen );
    int readn( char *pBuf, unsigned int n );
    int write(const char* pBuf, size_t sLen);

public:
    int getFd();
    int close();

public:
    int setNonBlock( void );
    int disableNagle( void );

private:
    int m_iSocketFd;
};

#endif
