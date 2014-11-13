#include "SlaveAgent.h"
#include "comm/Error.h"
#include "comm/Epoll.h"
#include <sys/epoll.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

SlaveAgent::SlaveAgent(TCPSocket &clientSocket, std::string &fileName, std::map< std::string , int > *pMap , int *pJobCount):
    m_TcpSocket(clientSocket),m_FileName(fileName),m_pWordCountBuffer(pMap),m_pJobCount(pJobCount) {

}

SlaveAgent::~SlaveAgent(){

}

int SlaveAgent::readData(){
    struct WordPair wordPair;
    memset(&wordPair, 0 , sizeof(struct WordPair));
    
    int n = m_TcpSocket.read( &wordPair, sizeof(struct WordPair) );
    if( n < 0){
       perror("In SlaveAgent::readData() read error!\n");
       return FAILED;
    }else if(n == 0){
        *(m_pJobCount) -= 1;
        if( *m_pJobCount == 0){
            Epoll::getInstance()->setEndTime();
            printWordMap();     

            std::cout << "spend time:" << Epoll::getInstance()->getSpendTime() <<"us"<<std::endl;
        }

        m_TcpSocket.close();
        delete this;
    }else if( n > 0 ){
        std::string word;
        word = wordPair.word;
        (*m_pWordCountBuffer)[ word ] += wordPair.count;
    }

    return SUCCESSFUL;
}

int SlaveAgent::writeData(){
    int n = m_TcpSocket.write( const_cast<char *>(m_FileName.c_str()), m_FileName.size() + 1);
    if( n < 0 ){
        perror("In SlaveAgent::writeData write error!\n");
        return FAILED;
    }else{
        if(Epoll::getInstance()->doEvent(this, EPOLL_CTL_MOD,m_TcpSocket.getFd(), EPOLLIN) < 0 ){
            perror("In SlaveAgent::writeData error!\n");
            return FAILED;
        }
    }
    
    return SUCCESSFUL;
}

void SlaveAgent::printWordMap(){
    std::map<std::string, int >::iterator mapIt;
    for(mapIt = m_pWordCountBuffer->begin(); mapIt != m_pWordCountBuffer->end(); ++mapIt){
        std::cout << mapIt->first << " " << mapIt->second << std::endl;
    }
}
