/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-07 20:58
#
# Filename: SocketAddress.h
#
# Description: 
#
=============================================================================*/
#ifndef SOCKETADDRESS_H_
#define SOCKETADDRESS_H_
#include <string>
#include <netinet/in.h>

class SocketAddress{
public:
    static int m_iIpType;

public:
    SocketAddress();
    SocketAddress( const char* pIpAddress, unsigned short nPort );
    ~SocketAddress();

public:
    void setAddress( const char* pIpAddress, unsigned short nPort );
    const char* getIp( void )const;
    unsigned short getPort(void )const;

    void setPort( unsigned short nPort);
    void setIp( const char* pIpAddress);

    sockaddr_in getAddr();
    int getAddr( sockaddr_in& addr );
    
private:
    std::string m_strIp;
    unsigned short m_nPort;
    std::string m_str;
};

#endif

