#include "WordCountClientAgent.h"
#include "comm/Epoll.h"

int main(){
    Epoll::getInstance()->initialize( 256 );
    WordCountClientAgent clientAgent("127.0.0.1",54321);

    clientAgent.initial();
    Epoll::getInstance()->run();

    return 0; 
}

