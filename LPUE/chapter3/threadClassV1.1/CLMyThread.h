#ifndef CLMYTHREAD_H
#define CLMYTHREAD_H
#include "CLThread.h"
class CLMyThread:public CLThread{
public:
	virtual CLStatus runThreadFunction(){
		long i = (long)threadContext;
		cout << i <<endl;
		return CLStatus(0,0);
	}

};

#endif


