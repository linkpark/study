#include "CLThread.h"
CLStatus CLThread::run(){
	int r = pthrad_create(&threadId,0,startFunctionOfThread,this);
	if(r != 0 ){
		CLLogger::writeLogMessage("In CLThread run,thread create error!");
		return CLStatus(-1,0);
	}
	
	return CLStatus(0,0);
}

CLStatus CLThread::waitForDeath(){
	int r = pthread_join(threadId,0);
	if(r != 0){
		CLLogger::writeLogMessage("In CLThread waitForDeath,pthread_join error!");
		return CLStatus(-1,0)
	}

	return CLStatus(0,0);
}

void* CLThread::startFunctionOfThread(void *pThis){
	CLThread *pThreadThis = (CLThread *)pThis;
	pThreadThis->coordinator-> returnControlRights();
}

