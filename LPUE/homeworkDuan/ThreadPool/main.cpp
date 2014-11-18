#include "ThreadPoolDispatcher.h"
#include "ThreadPool.h"
#include "ThreadWorkItem.h"
#include "ArithmeticWorkItem.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

int main(){
    ThreadPool *threadPool = new ThreadPool;
    ThreadWorkItem *pThreadWorkItem;
    
    struct timeval begin,end;

    gettimeofday(&begin,NULL);

    threadPool->initial( 5 );

    ThreadPoolDispatcher dispatcher(threadPool, "dispatcher.fifo" );
    dispatcher.initial( 5 );

    for(int i = 0 ; i < 50000 ; i++){
        pThreadWorkItem = new ArithmeticWorkItem( dispatcher.getWriteBackFd(), i , 2 , DIV );
        pThreadWorkItem->setTaskID( i );
        dispatcher.sendTask( pThreadWorkItem );
    }

    dispatcher.reciveTask( 50000 );
    gettimeofday(&end,NULL);
    cout << "time spend: "<< ( end.tv_sec - begin.tv_sec ) * 1000000 + end.tv_usec - begin.tv_usec << " us" <<endl;
    return 0;
}
