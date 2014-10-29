/*
 * =================================================================
 *
 *            Filename:    TCPSocket.cpp
 *
 *         Description:    the implement of class TCPSocket 
 *
 *             Version:    v1.0
 *             Created:    2014-10-28 01:09
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#include "TCPSocket.h"
#include "Error.h"
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>

TCPSocket::TCPSocket():m_iSocketFd( -1 ){
}

TCPSocket::~TCPSocket(){}

int TCPSocket::generateSocket( void ){
    m_iSocketFd = socket( AF_INET, SOCK_STREAM ,0 );

    if( m_iSocketFd < 0 ){
        std::cerr<< "In TCPSocket::generateSocket socket error!" << std::endl;
        return FAILED;
    }

    return SUCCESSFUL; 
} 

int TCPSocket::getFd()const{
    return m_iSocketFd;
}

int TCPSocket::close(){
    if( -1 == m_iSocketFd ){
        return SUCCESSFUL;
    }

    if( ::close(m_iSocketFd) < 0){
        std::cerr << "In TCPSocket::close close error!" <<std::endl;
        return FAILED;
    }    
    
    m_iSocketFd = -1;
    
    return SUCCESSFUL;
}

int TCPSocket::read( void *buf, size_t n ){
    int readSize = ::read(m_iSocketFd , buf , n );

    return readSize;
}

int TCPSocket::write( void *buf, size_t n ){
    int writeSize = ::write(m_iSocketFd, buf, n);

    return writeSize;
}

int TCPSocket::listen( int backlog ){
    if( ::listen( m_iSocketFd , backlog ) < 0 ){
        std::cerr << "in TCPSocket::listen listen error" << std::endl;
        return FAILED;
    }

    return SUCCESSFUL;
}

int TCPSocket::bind( SocketAddress &sockAddr ){
    struct sockaddr_in sockAddrStruct;
    sockAddrStruct = sockAddr.getAddr();

    if(::bind( m_iSocketFd , (struct sockaddr* )&sockAddrStruct, sizeof(sockAddrStruct) ) < 0){
        std::cerr << "in TCPSocket::bind bind error!" <<std::endl;
        return FAILED;
    }

    return SUCCESSFUL;
}

int TCPSocket::connect( SocketAddress &sockAddr ){
    struct sockaddr_in addr;
    int ret;

    addr = sockAddr.getAddr();
    
    ret = ::connect( m_iSocketFd , (struct sockaddr*)&addr , sizeof(addr) );
    return ret;
}

int TCPSocket::setNonBlock(){
    int val;
   
    val = fcntl( m_iSocketFd , F_GETFL, 0 );
    if( val < 0){
        std::cerr << "in TCPSocket::setNonBlock fcntl get error! " <<std::endl;
        return val;
    }

    val |= O_NONBLOCK;

    if( fcntl( m_iSocketFd , F_SETFL, val) < 0 ){
        std::cerr << "in TCPSocket::setNonBlock fcntl set error! " <<std::endl;
        return FAILED; 
    }

    return SUCCESSFUL;
}

