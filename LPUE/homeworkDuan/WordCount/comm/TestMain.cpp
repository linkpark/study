#include "TCPListenAgent.h"
#include "Epoll.h"
#include "ClientAgent.h"
#include "EchoTask.h"

int main(){
    Epoll::getInstance()->initialize( 256 );
    TCPListenAgent< ClientAgent, EchoTask > tcpListenAgent( 54321,"0" );    
    tcpListenAgent.initial();

    Epoll::getInstance()->run();

    return 0; 
}
