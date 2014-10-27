#ifndef TCPLISTENAGENT_H_
#define TCPLISTENAGENT_H_
#include "Agent.h"
#include "SocketAddress.h"

class TCPListenAgent:public Agent{
public:
    TCPListenAgent( int port, const char* pIpAddr );
    ~TCPListenAgent();

public:
    int readData( void );
    int writeData( void );
    int initial( void );

private:
    inline void initial( void ); 

private:
    SocketAddress m_SocketAddress; 
};

#endif
