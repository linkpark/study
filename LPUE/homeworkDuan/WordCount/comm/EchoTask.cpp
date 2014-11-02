/*
 * =================================================================
 *
 *            Filename:    EchoTask.cpp
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-01 19:45
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#include "EchoTask.h"
#include "ClientAgent.h"
#include "Error.h"
#include "Epoll.h"
#include <sys/epoll.h>
#include <iostream>
#include <string.h>

int EchoTask::readTask( void *pContext ){
    ClientAgent *pClientAgent = static_cast< ClientAgent* >(pContext);
    if( Epoll::getInstance()->doEvent(pClientAgent, EPOLL_CTL_MOD, pClientAgent->getSocketFd(),EPOLLOUT ) < 0){
        std::cerr << "In EchoTask::readTask error!" <<std::endl;
        return FAILED;
    } 

    return SUCCESSFUL;
}

int EchoTask::writeTask( void *pContext ){
    ClientAgent *pClientAgent = static_cast< ClientAgent* >(pContext);
    if( Epoll::getInstance()->doEvent(pClientAgent,EPOLL_CTL_MOD, pClientAgent->getSocketFd(),EPOLLIN ) < 0){
        std::cerr << "In EchoTask::readTask error!" <<std::endl;
        return FAILED;
    } 
    
    return SUCCESSFUL;
}
