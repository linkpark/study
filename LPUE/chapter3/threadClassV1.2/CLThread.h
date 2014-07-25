#ifndef CLTHREAD_H
#define CLTHREAD_H
#include "stadx.h"
#include "CLStatus.h"
#include "CLLogger.h"
#include "CLExecutive.h"
#include "CLExecutiveFunctionProvider.h"

class CLThread:public CLExecutive{
public:
	explicit CLThread(CLExecutiveFunctionProvider *pExecutiveFunctionProvider):CLExecutive(pExecutiveFunctionProvider){
	}

	virtual ~CLThread(){
	}
	
	virtual CLStatus run(void *threadContextParam = 0);
	virtual CLStatus waitForDeath();

private:
	static void *startFunctionOfThread(void *threadContextParam);

protected:
	void *threadContext;
	pthread_t threadId;		
};
#endif

