/*
 * =================================================================
 *
 *            Filename:    WordCountClientAgent.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-12 15:46
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef WORDCOUNTCLIENTAGENT_H_
#define WORDCOUNTCLIENTAGENT_H_
#include "comm/Agent.h"
#include "comm/SocketAddress.h"
#include "comm/TCPSocket.h"
#include <map>
#include <string>

class WordCountClientAgent:public Agent{
public:
    WordCountClientAgent( const char* pIpAddr, int port );
    ~WordCountClientAgent();

public:
    int initial( void );
    int readData( void );
    int writeData( void );

private:
    TCPSocket m_ClientSocket;
    SocketAddress m_ServerSockAddress;
    std::map< std::string, int > m_WordList;
    char m_pFileName[256];
    int m_wordListSize;
};

#endif

