#ifndef CLTHREAD_H
#define CLTHREAD_H
#include "stadx.h"
#include "CLStatus.h"
#include "CLLogger.h"

class CLThread{
public:
	CLThread(){
	}
	virtual ~CLThread(){
	}
	
	CLStatus run(void *threadContextParam = 0);
	CLStatus waitForDeath();

private:
	virtual CLStatus runThreadFunction() = 0;
private:
	static void *startFunctionOfThread(void *threadContextParam);

protected:
	void *threadContext;
	pthread_t threadId;		
};

#endif

