#include "ThreadPoolDispatcher.h"
#include "ThreadPool.h"
#include "ThreadWorkItem.h"
#include "ArithmeticWorkItem.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main(){
    ThreadPool *threadPool = new ThreadPool;
    ThreadWorkItem *pThreadWorkItem;

    threadPool->initial( 5 );

    ThreadPoolDispatcher dispatcher(threadPool, "dispatcher.fifo" );
    dispatcher.initial( 5 );

    for(int i = 0 ; i < 1000 ; i++){
        pThreadWorkItem = new ArithmeticWorkItem( dispatcher.getWriteBackFd(), i , i , ADD );
        pThreadWorkItem->setTaskID( i );
        cout << pThreadWorkItem <<endl;

        dispatcher.sendTask( pThreadWorkItem );
    }

    dispatcher.reciveTask();
    
    return 0;
}
