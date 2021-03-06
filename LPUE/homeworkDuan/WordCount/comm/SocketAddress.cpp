/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-07 20:58
#
# Filename: SocketAddress.cpp
#
# Description: 
#
=============================================================================*/
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "Error.h"
#include "SocketAddress.h"

const int IPV4LEN = 15;
const int IPV6LEN = 39;
const char* ANYADDR = "0";
const char* IPV4_ANYADDR = "0.0.0.0";
const char* IPV6_ANYADDR = "::1";
//const int IPV6 = 1;
const int IPV4 = 0;

int SocketAddress::m_iIpType = IPV4;

SocketAddress::SocketAddress():
   m_nPort(0),m_str( "" ){
    if( IPV4 == m_iIpType )
        m_strIp = IPV4_ANYADDR;

    else
        m_strIp = IPV6_ANYADDR;
}

SocketAddress::SocketAddress( const char* pIpAddress, unsigned short nPort):
    m_nPort(nPort){
    if(IPV4 == m_iIpType ){
        if( strlen( pIpAddress ) > IPV4LEN || 0 == strcmp( pIpAddress,ANYADDR ) ){
            m_strIp = std::string( IPV4_ANYADDR );  
        }
        else{
            m_strIp = std::string( pIpAddress );
        }
    }
    else{
        if( strlen( pIpAddress ) > IPV6LEN || 0 == strcmp( pIpAddress, ANYADDR) ){
            m_strIp = std::string( IPV6_ANYADDR );
        }
        else{
            m_strIp = std::string( pIpAddress );
        } 
    }    
}

SocketAddress::~SocketAddress(){}

void SocketAddress::setAddress( const char* pIpAddress, unsigned short nPort ){
    m_nPort = nPort;
    if( IPV4 == m_iIpType ){
        if( strlen( pIpAddress ) <= IPV4LEN && strcmp( pIpAddress , ANYADDR ) != 0 )
            m_strIp = std::string( pIpAddress );
    }    
    else{
        if( strlen( pIpAddress ) <= IPV6LEN && strcmp( pIpAddress , ANYADDR ) != 0)
            m_strIp = std::string( pIpAddress );
    }
}

void SocketAddress::setPort( unsigned short nPort ){
    m_nPort = nPort;
} 

void SocketAddress::setIp( const char* pIpAddress){
    m_strIp = std::string(pIpAddress);
}

sockaddr_in SocketAddress::getAddr( void ){
    sockaddr_in addr;
    
    memset( &addr, 0 ,sizeof(addr) );
    addr.sin_family = AF_INET;
    addr.sin_port = htons( m_nPort );
    addr.sin_addr.s_addr = inet_addr( m_strIp.c_str() );

    return addr;
}

int SocketAddress::getAddr( sockaddr_in& addr){
    memset( &addr, 0 ,sizeof(addr) );
    addr.sin_family = AF_INET;
    addr.sin_port = htons( m_nPort );
    if(inet_pton(AF_INET, m_strIp.c_str(), &addr.sin_addr) == 1)
        return SUCCESSFUL;
    else
        return FAILED;    
}

