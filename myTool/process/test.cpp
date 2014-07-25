/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified:	2014-05-17 15:37
#
# Filename:		test.cpp
#
# Description: 
#
=============================================================================*/
#include "Logger.h"
#include "Error.h"
#include "ExecutiveFuncProvider.h"
#include "Thread.h"
#include "Mutex.h"
#include "CriticalSection.h"
#include <iostream>
#include <unistd.h>
#include <errno.h>

using namespace std;

struct SPara{
    int Flag;
    Mutex mutex;
};

class ParaPrinter:public ExecutiveFuncProvider{
public:
    ParaPrinter(){
    }

    virtual ~ParaPrinter(){
    }

    void test(){
        throw 32;
    }

    virtual int runExecutiveFunc(void *pContext){
        try{
            struct SPara* p = (struct SPara*)pContext;
            
            CriticalSection cs( &(p->mutex) );

            p->Flag++;
            cout << p->Flag <<endl;
            test();
        }
        catch(...){
            cout << "exception" <<endl;
        }

        return SUCCESSFUL;
    }
};

int main(){
    ExecutiveFuncProvider *printer = new ParaPrinter();
    Thread *threadExecutive = new Thread(printer);
    Thread *threadExecutive1 = new Thread(printer);
    struct SPara *p = new struct SPara;
    p->mutex.initLock();
    p->Flag = 0;

    threadExecutive->run( (void*)p );
    threadExecutive1->run( (void*)p );
    sleep(2);

    {
        CriticalSection cs( &(p->mutex) );
        p->Flag ++;
        cout << p->Flag << endl;
    }
    
    p->mutex.destoryLock();
    delete p;
    delete threadExecutive;
    delete threadExecutive1;
    delete printer;

    return SUCCESSFUL;
}

