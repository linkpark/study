/*
 * =================================================================
 *
 *            Filename:    ClientAgent.cpp
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-01 14:43
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */

#include "ClientAgent.h"
#include "Error.h"
#include <iostream>
#include <cstring>

int ClientAgent::readData( void ){
    memset(m_pBuf, 0, 100);
    int n = m_TCPClientSocket.read( m_pBuf, 100 );
    if( n < 0){
        std::cerr << "In ClientAgent::readData error!" << std::endl;
        return FAILED;
    }else if( n == 0 ){
        m_TCPClientSocket.close();
        delete this;
    }else if( n > 0 ){
        m_pTask->readTask( this );
    }

    return SUCCESSFUL;
}

int ClientAgent::writeData( void ){
    int n = m_TCPClientSocket.write( m_pBuf, 100);
    if( n < 0){
        std::cerr << "InClientAgent::writeData error!" <<std::endl;
        return FAILED;
    }else{
        m_pTask->writeTask( this );
    }

    return SUCCESSFUL;
}

int ClientAgent::getSocketFd()const{
    return m_TCPClientSocket.getFd();
}

