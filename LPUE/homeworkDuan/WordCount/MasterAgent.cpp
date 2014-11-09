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
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <iostream>

using namespace std;
const int LISTEN_NUM = 1024;

MasterAgent::MasterAgent( const char* pAddr , int port){
    m_SocketAddress.setAddress( pAddr, port );
}

MasterAgent::~MasterAgent(){

}

int MasterAgent::initial(const char* path){
    if( FAILED == scanTheDir( path )){
        perror("In MasterAgent::initial error!\n");
        return FAILED;
    }

    if( FAILED == initialSocket()){
        perror("In MasterAgent::initial error!\n");
        return FAILED;
    }

    return SUCCESSFUL;
}

int MasterAgent::readData(){

    return SUCCESSFUL;
}

int MasterAgent::writeData(){

    return SUCCESSFUL;
}

int MasterAgent::scanTheDir(const char* path){
    DIR *dirHandler = opendir( path );
    struct dirent *entry;
    struct stat statBuf;

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
            string path( entry->d_name );
            m_FileNameList.push_back( path );
        }    
    }
    
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

