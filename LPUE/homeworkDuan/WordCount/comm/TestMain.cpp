#include "TCPListenAgent.h"
#include "Epoll.h"
#include "ClientAgent.h"
#include "EchoTask.h"

int main(){
    Epoll::getInstance()->initialize( 256 );
    TCPListenAgent< ClientAgent, EchoTask > tcpListenAgent( 54321, "127.0.0.1");    
    tcpListenAgent.initial();

    Epoll::getInstance()->run();

    return 0; 
}
