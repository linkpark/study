#ifndef CLTHREAD_H
#define CLTHREAD_H
#include "stadx.h"
#include "CLStatus.h"
#include "CLLogger.h"

class CLThread{
public:
	CLThread(){

	}
	~CLThread(){

	}
	
	CLStatus run(void *threadContextParam = 0);
	CLStatus waitForDeath();

private:
	CLStatus runThreadFunction();

private:
	static void *startFunctionOfThread(void *threadContextParam);

private:
	void *threadContext;
	pthread_t threadId;		
};

#endif

