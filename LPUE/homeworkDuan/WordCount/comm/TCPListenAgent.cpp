#include "TCPListenAgent.h"

TCPListenAgent::TCPListenAgent( int port, const char* pIpAddr){
    m_SocketAddress.setAddress( pIpAddr, port );
}

int TCPListenAgent::initial( void ){    
}

