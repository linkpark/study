#include "WordCountClientAgent.h"
#include "comm/Epoll.h"
#include <iostream>

using namespace std;

int main(){
    Epoll::getInstance()->initialize( 256 );
    WordCountClientAgent clientAgent("127.0.0.1",54321);

    clientAgent.initial();
    cout << "word count process begin " <<endl;
    Epoll::getInstance()->run();

    return 0; 
}

