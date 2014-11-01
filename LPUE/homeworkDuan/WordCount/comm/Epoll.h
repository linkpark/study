#ifndef EPOLL_H_
#define EPOLL_H_
#include "Agent.h"
//using single pattern
class Epoll{
private:
    Epoll();
    Epoll( const Epoll& );
    Epoll& operator=( Epoll& );

    virtual ~Epoll();
 
public:   
    int getEpollFd()const;
    int initialize( int );
    int doEvent( Agent* pAgentPtr, int op, int fd, unsigned int event); 
    void run( void );

public:
    static Epoll* getInstance();

private:
    //state controll
    bool m_bIsCreate;

    int m_iEpollFd;
    int m_iEventSize;
    struct epoll_event *m_pEpollEvents;

    static Epoll* m_spEpollObj;
};

#endif
