#ifndef CLTHREAD_H
#define CLTHREAD_H
#include "CLExecutive.h"
class CLThread:public CLExecutive{
public:
	CLThread(CLCoordinator *coordinatorParam){
		CLExecutive(coordinatorParam);
	}

	virtual ~CLThread(){
	}

	virtual CLStatus run();
	virtual CLStatus waitForDeath();

private:
	static void *startFunctionOfThread(void *pThis);

protected:
	pthread_t threadId;
}

#endif
