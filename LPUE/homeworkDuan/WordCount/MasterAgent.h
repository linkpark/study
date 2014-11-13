/*
 * =================================================================
 *
 *            Filename:    MasterAgent.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-02 13:34
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef MASTERAGENT_H_
#define MASTERAGENT_H_
#include "comm/Agent.h"
#include "comm/TCPSocket.h"
#include "comm/SocketAddress.h"
#include <vector>
#include <string>
#include <map>

class MasterAgent:public Agent{
private:
    typedef std::vector< std::string > file_list_type;
    
public:
    MasterAgent( const char* pAddr, int port );
    ~MasterAgent();
    
    int initial( const char* );
    int readData( void );
    int writeData( void );

private:
    inline int scanTheDir( const char* );
    inline int initialSocket();

private:
    file_list_type m_FileNameList;
    int m_CurrentFileSeq;

    TCPSocket m_MasterSocket;
    SocketAddress m_SocketAddress;
    std::map< std::string, int > *m_WordCountMap;
    int *m_pJobCount;    
};

#endif

