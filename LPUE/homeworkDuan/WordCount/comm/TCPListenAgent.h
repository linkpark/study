/*
 * =================================================================
 *
 *            Filename:    TCPListenAgent.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-01 14:07
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef TCPLISTENAGENT_H_
#define TCPLISTENAGENT_H_
#include "Agent.h"
#include "SocketAddress.h"
#include "TCPSocket.h"
#include "Error.h"
#include "Epoll.h"

#include <sys/epoll.h>
#include <iostream>

const int LISTEN_NUM = 1024;

template<class ClientAgent,class Task>
class TCPListenAgent:public Agent{
public:
    TCPListenAgent( int port, const char* pIpAddr ){
    	m_SocketAddress.setAddress( pIpAddr, port );
    }
    ~TCPListenAgent();

public:
    int readData( void ){
	    SocketAddress clientAddr;
	    int clientFd;
	    
	    clientFd = m_TCPListenSoket.accept( clientAddr );
	    if( clientFd < 0 ){
            std::cerr << "In TCPListenAgent::readData error " <<std::endl;
            return FAILED;
        }  

        TCPSocket clientSocket( clientFd );
        Task *pClientTask = new Task();
        ClientAgent *pClientAgent = new ClientAgent( clientSocket, pClientTask );

        if( Epoll::getInstance()->doEvent(pClientAgent, EPOLL_CTL_ADD , clientFd , EPOLLIN ) < 0 ){
            std::cerr << "In TCPListenAgent::readData doEvent error! " << std::endl;
            return FAILED;
        }
                
	    return SUCCESSFUL;  
    }

    int writeData( void ){
    	return SUCCESSFUL;
    }

    int initial( void ){
	  	if( m_TCPListenSoket.generateSocket() < 0 ||
        m_TCPListenSoket.setNonBlock() < 0 ||
        m_TCPListenSoket.bind( m_SocketAddress ) < 0 ||
        m_TCPListenSoket.listen( LISTEN_NUM ) <0){
        	std::cerr << "In TCPListenAgent::initial error!" << std::endl;
        	return FAILED;
    	}
    
    	return SUCCESSFUL;
    }

    void setTask(Task *pTask){
        m_pTask = pTask; 
    }

private:
    SocketAddress m_SocketAddress; 
    TCPSocket m_TCPListenSoket;
};

#endif

