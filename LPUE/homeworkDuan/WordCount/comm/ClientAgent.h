/*
 * =================================================================
 *
 *            Filename:    ClientAgent.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-01 14:17
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef CLIENTAGENT_H_
#define CLIENTAGENT_H_
#include "Agent.h"
#include "TCPSocket.h"
#include "Task.h"

class ClientAgent:public Agent{
public:
    ClientAgent(TCPSocket& clientSocket,Task *clientTask ):
        Agent( clientTask ),m_TCPClientSocket( clientSocket ){
    
    }
        
    virtual ~ClientAgent(){
    }

public:
    virtual int readData( void );
    virtual int writeData( void );

    int setBuf();
    int getSocketFd()const;

private:
    TCPSocket m_TCPClientSocket;    
    char m_pBuf[100];
};

#endif
