#include "MasterAgent.h"
#include "comm/Epoll.h"
#include <iostream>

using namespace std;

int main(){
    Epoll::getInstance()->initialize( 256 );
    MasterAgent masterAgent( "0",54321 );    
    masterAgent.initial("word");

    cout << "epoll wait " <<endl;
    Epoll::getInstance()->run();

    return 0; 
}

