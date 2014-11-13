#include "MasterAgent.h"
#include "comm/Epoll.h"

int main(){
    Epoll::getInstance()->initialize( 256 );
    MasterAgent masterAgent( "0",54321 );    
    masterAgent.initial("word");

    Epoll::getInstance()->run();

    return 0; 
}

