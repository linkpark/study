#include "WordCountClientAgent.h"
#include "comm/Error.h"
#include "comm/Epoll.h"
#include <stdio.h>
#include <sys/epoll.h>
#include <string.h>
#include <fstream>
#include <iostream>

WordCountClientAgent::WordCountClientAgent( const char *pIpAddr, int port){
    m_ServerSockAddress.setAddress( pIpAddr, port );
}

WordCountClientAgent::~WordCountClientAgent(){
}

int WordCountClientAgent::initial( void ){
    if( m_ClientSocket.generateSocket() < 0 ||
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
        std::cout << "begin scan " << m_pFileName << std::endl;
        scanFile(); 

        if( (Epoll::getInstance()->doEvent( this,EPOLL_CTL_MOD,m_ClientSocket.getFd(),EPOLLOUT )) < 0){
            perror("In WordCountClientAgent::readData() error!\n");
            return FAILED;    
        }
    }

    return SUCCESSFUL;
}

int WordCountClientAgent::writeData(){   
    struct WordPair wordPair;
    
    std::map< std::string, int >::iterator mapIt;

    for( mapIt = m_WordList.begin(); mapIt != m_WordList.end(); ++mapIt){
        memset(&wordPair, 0 , sizeof(struct WordPair));
        wordPair.count = mapIt->second;    
        sprintf( wordPair.word, "%s" , mapIt->first.c_str() ); 

        if( m_ClientSocket.write( &wordPair, sizeof(wordPair)) < 0){
            perror("In WordCountClientAgent::write error!\n");
            return FAILED;        
        } 
    }

    m_ClientSocket.close();

    return SUCCESSFUL;
}

int WordCountClientAgent::scanFile( void ){
    std::ifstream inputFile( m_pFileName );
    std::string word;

    while( inputFile >> word ){
        m_WordList[ word ]++;
    }

    return SUCCESSFUL;
}


