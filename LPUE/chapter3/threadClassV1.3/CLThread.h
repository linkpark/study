#include "stadx.h"
#include "CLStatus.h"
#include "CLLogger.h"

template <typename T>
class CLThread{
public:
	CLStatus run(void *threadContextParam = 0){
		threadContext = threadContextParam;

		int r = pthread_create(&threadId,0,startFunctionOfThread,this);
		if(r != 0){
			CLLogger::writeLogMessage("In CLThread::Run(),pthread_create error!",r);
			return CLStatus(-1,0);

		}

		return CLStatus(0,0);
	}

	CLStatus waitForDeath(){
		int r = pthread_join(threadId,0);
		if( r != 0 ){
		CLLogger::writeLogMessage("In CLThread::waitForDeath(),pthread_join error" , r);
		return CLStatus(-1,0);
		}

		return CLStatus(0,0);
	}

private:
	static void *startFunctionOfThread(void *threadContextParam){
		T *pThreadThis = (T*)threadContextParam;

		CLStatus s = pThreadThis->runThreadFunction();
			
		return (void*)s.constReturnCode;
	}

protected:
	void *threadContext;
	pthread_t threadId;	
};
