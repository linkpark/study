/*
 * =================================================================
 *
 *            Filename:    Epoll.cpp
 *
 *         Description:    
 *
 *             Version:    
 *             Created:    2014-10-24 13:26
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
/*
 * =================================================================
 *
 *            Filename:    Epoll.cpp
 *
 *         Description:    
 *
 *             Version:    
 *             Created:    2014-10-24 13:26
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#include "Error.h"
#include "Epoll.h"
#include <sys/epoll.h>
#include <errno.h>
#include <iostream>
#include <cstring>

using namespace std;
const int EPOLL_TIME_OUT_LEN = -1;

Epoll::Epoll():m_iEpollFd(-1),m_pEpollEvents(NULL){ 
    m_iEventSize = 0;
    m_bIsCreate = false;
}

Epoll::~Epoll(){
    if(m_bIsCreate){
        delete [] m_pEpollEvents;
        m_pEpollEvents = NULL;
    }
}

int Epoll::initialize(int eventsNumber){
    m_iEventSize = eventsNumber;
    m_iEpollFd = epoll_create( m_iEventSize );

    if(m_iEpollFd < 0){
        cerr << "in Epoll::initialize() epoll_create error!" <<endl; 
        return FAILED;
    }
    
    m_pEpollEvents = new epoll_event[ m_iEventSize ];
    memset(m_pEpollEvents, 0 , sizeof(epoll_event) * m_iEventSize );
    
    m_bIsCreate = true;

    return SUCCESSFUL; 
}

int Epoll::doEvent( Agent* pAgentPtr, int op , int fd, uint32_t event){
    struct epoll_event ev;
    memset( &ev,0,sizeof(ev) );
   
    ev.events = event;
    ev.data.ptr = pAgentPtr; 

    if(epoll_ctl( m_iEpollFd ,op, fd, &ev)){
        cerr << "in Epoll::doEvent() epoll_ctl error!" <<endl;
        return FAILED; 
    }

    return SUCCESSFUL;
}

Epoll* Epoll::getInstance(){
    if( NULL == m_spEpollObj ){
        m_spEpollObj = new Epoll();
    }

    return m_spEpollObj;
}

void Epoll::run( void ){
    int ndfs = 0;
    Agent *pAgent; 

    while( true ){
        ndfs = epoll_wait( m_iEpollFd , m_pEpollEvents , m_iEventSize , EPOLL_TIME_OUT_LEN );

        if(ndfs < 0){
            if( EINTR == errno )
                continue;
            else{
                cerr << "in Epoll::run() epoll_wait() error!" <<endl;
                exit(FAILED);
            }
        }

        for( int i = 0; i < ndfs ; ++i ){
            pAgent = static_cast<Agent*>( m_pEpollEvents[i].data.ptr );
            if(NULL == pAgent){
                cerr << "in Epoll::run() pAgent == NULL" <<endl;
                continue;
            }

            if( EPOLLOUT & m_pEpollEvents[i].events ){
                if( FAILED == pAgent->writeData() ){
                    cerr << "in Epoll::run() pAgent->writeData() error!" <<endl;
                }
            }

            if( EPOLLIN & m_pEpollEvents[i].events ){
                if( FAILED == pAgent->readData() ){
                    cerr << "in Epoll::run() pAgent->readData() error!" <<endl;
                }
            }
        }
    }
}

