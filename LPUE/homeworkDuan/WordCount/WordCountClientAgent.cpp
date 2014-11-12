#include "WordCountClientAgent.h"
#include "comm/Error.h"
#include "comm/Epoll.h"
#include <stdio.h>
#include <sys/epoll.h>
#include <string.h>

WordCountClientAgent::WordCountClientAgent( const char *pIpAddr, int port){
    m_ServerSockAddress.setAddress( pIpAddr, port );
}

WordCountClientAgent::~WordCountClientAgent(){
}

int WordCountClientAgent::initial( void ){
    if( m_ClientSocket.generateSocket() < 0 ||
            m_ClientSocket.setNonBlock() < 0 ||
            m_ClientSocket.connect( m_ServerSockAddress ) < 0){
        perror("In WordCountClientAgent::initial() error!\n");
        return FAILED;
    }

    if( (Epoll::getInstance()->doEvent(this, EPOLL_CTL_ADD, m_ClientSocket.getFd() , EPOLLIN) ) < 0 ){
        perror("In WordCountClientAgent::initial() error!\n");
        return FAILED;        
    }
    
    return SUCCESSFUL;
}

int WordCountClientAgent::readData( void ){
    memset(m_pFileName, 0 , 256);
    int n = m_ClientSocket.read( m_pFileName, 256 );
    if( n < 0){
        perror("In WordCountClientAgent::readData() error!\n");
        return FAILED;
    }else if( n == 0){
        perror("Server Has close \n");
        m_ClientSocket.close();
        delete this;
    }else{
        
        if( (Epoll::getInstance()->doEvent( this,EPOLL_CTL_MOD,m_ClientSocket.getFd(),EPOLLOUT )) < 0){
            perror("In WordCountClientAgent::readData() error!\n");
            return FAILED;    
        }
    }

    return SUCCESSFUL;
}

int WordCountClientAgent::writeData(){   

    return SUCCESSFUL;
}


