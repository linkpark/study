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
#include <vector>
#include <string>

class MasterAgent:public Agent{
private:
    typedef std::vector< std::string > file_list_type;

public:
    MasterAgent();
    ~MasterAgent();
    
    int initial( const char* );
    int readData( void );
    int writeData( void );

private:
    inline int scanTheDir( const char* );


private:
    file_list_type m_FileNameList;
    TCPSocket m_MasterSocket;
};

#endif

