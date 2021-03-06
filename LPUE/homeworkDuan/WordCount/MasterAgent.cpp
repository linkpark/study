/*
 * =================================================================
 *
 *            Filename:    MasterAgent.cpp
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
#include "MasterAgent.h"
#include "comm/Error.h"
#include "comm/Epoll.h"
#include "SlaveAgent.h"

#include <unistd.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
const int LISTEN_NUM = 1024;
class SlaveAgent;

MasterAgent::MasterAgent( const char* pAddr , int port){
    m_SocketAddress.setAddress( pAddr, port );
    m_WordCountMap = new std::map< std::string, int >;    
    m_CurrentFileSeq = 0;
}

MasterAgent::~MasterAgent(){
    delete m_WordCountMap;
}

int MasterAgent::initial(const char* path){
    pid_t childProcessId;

    if( FAILED == initialSocket()){
        perror("In MasterAgent::initial error!\n");
        return FAILED;
    }
    
    if( FAILED == scanTheDir( path )){
        perror("In MasterAgent::initial error!\n");
        return FAILED;
    }

    for(size_t i = 0 ; i < m_FileNameList.size(); i++ ){
        childProcessId = vfork();
        if( childProcessId == 0){
            if( execl("./WordCountMain","WordCountMain",NULL) < 0){
                perror("execl error!\n");
                return FAILED;
            }
        }else if( childProcessId < 0 ){
            perror("fork error!\n");
            return FAILED;
        }
    }

    return SUCCESSFUL;
}

int MasterAgent::readData(){
    SocketAddress clientAddr;
	int clientFd;
	    
	clientFd = m_MasterSocket.accept( clientAddr );
	if( clientFd < 0 ){
        std::cerr << "In TCPListenAgent::readData error " <<std::endl;
        return FAILED;
    }  

    TCPSocket clientSocket( clientFd );
    SlaveAgent *pSlaveAgent = new SlaveAgent(clientSocket, m_FileNameList[m_CurrentFileSeq], m_WordCountMap , m_pJobCount );
    m_CurrentFileSeq ++;

    if( Epoll::getInstance()->doEvent(pSlaveAgent, EPOLL_CTL_ADD , clientFd , EPOLLOUT ) < 0 ){
        std::cerr << "In TCPListenAgent::readData doEvent error! " << std::endl;
        return FAILED;
    }

    return SUCCESSFUL;
}

int MasterAgent::writeData(){
    return SUCCESSFUL;
}

int MasterAgent::scanTheDir(const char* path){
    DIR *dirHandler = opendir( path );
    struct dirent *entry;
    struct stat statBuf;
    
    m_pJobCount = new int;   

    if( NULL == dirHandler ){
        perror( "in MasterAgent::initial() opendir() error!\n" );
        return FAILED;
    }
    
    chdir( path );
    //traverse the directory
    while( (entry = readdir( dirHandler )) != NULL ){
        if(lstat(entry->d_name, &statBuf ) ){
            perror( "in MasterAgent::initial() lstat() error!\n" );
            return FAILED;
        }

        if( !S_ISDIR(statBuf.st_mode) ){
            string fileName( path );
            fileName.append("/");
            fileName.append( entry->d_name );
            
            m_FileNameList.push_back( fileName );
        }    
    }
    
    chdir( "../" );
    *m_pJobCount = m_FileNameList.size();

    return SUCCESSFUL;
}

int MasterAgent::initialSocket(){
	if( m_MasterSocket.generateSocket() < 0 ||
        m_MasterSocket.setNonBlock() < 0 ||
        m_MasterSocket.bind( m_SocketAddress ) < 0 ||
        m_MasterSocket.listen( LISTEN_NUM ) <0){
            perror("In TCPListenAgent::initial error!\n");
        	return FAILED;
    }
    
    Epoll::getInstance()->doEvent(this, EPOLL_CTL_ADD, m_MasterSocket.getFd(), EPOLLIN );
    return SUCCESSFUL;
}

