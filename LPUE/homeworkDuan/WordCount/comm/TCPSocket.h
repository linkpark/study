/*
 * =================================================================
 *
 *            Filename:    TCPSocket.h
 *
 *         Description:    TCPSocket class  
 *
 *             Version:    v1.0
 *             Created:    2014-10-28 00:18
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef TCPSOCKET_H_
#define TCPSOCKET_H_
#include <sys/types.h>
#include "SocketAddress.h"

class SocketAddress;
class TCPSocket{
public:
    TCPSocket();
    TCPSocket(int fd);
    ~TCPSocket();   

public:
    int generateSocket( void );
    int getFd()const;
    int close( void );
    int read( void* buf,size_t n);
    int write( void* buf, size_t n);
    int listen( int backlog );
    int bind( SocketAddress& );
    int connect( SocketAddress& );
    int accept( SocketAddress& );

    int setNonBlock(); 

private:
    int m_iSocketFd;
     
};
#endif
