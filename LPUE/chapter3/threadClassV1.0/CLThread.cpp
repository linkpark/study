#include "CLThread.h"

CLStatus CLThread::run(void *threadContextParam){
	threadContext = threadContextParam;

	int r = pthread_create(&threadId,0,startFunctionOfThread,this);

	if(r != 0){
		CLLogger::writeLogMessage("In CLThread::Run(),pthread_create error!",r);
		return CLStatus(-1,0);
	}
	
	return CLStatus(0,0);
}

CLStatus CLThread::waitForDeath(){
	int r = pthread_join(threadId,0);
	if( r != 0 ){
		CLLogger::writeLogMessage("In CLThread::waitForDeath(),pthread_join error" , r);
		return CLStatus(-1,0);
	}

	return CLStatus(0,0);
}

void *CLThread::startFunctionOfThread(void *threadContextParam){
	CLThread *pThreadThis = (CLThread*)threadContextParam;

	CLStatus s = pThreadThis->runThreadFunction();
	return (void *)s.constReturnCode;
}

CLStatus CLThread::runThreadFunction(){
	cout << "Hello world" <<endl;
	//cout << (long)threadContext <<endl;
	return CLStatus(0,0);
}

