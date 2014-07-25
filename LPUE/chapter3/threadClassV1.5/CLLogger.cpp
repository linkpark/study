#include "CLLogger.h"

CLLogger* CLLogger::logObj = NULL;
CLLogger::CLLogger(){
	fileFd = open(LOG_FILE_NAME,O_RDWR|O_CREAT|O_APPEND,S_IRUSR|S_IWUSR);
	if(fileFd == -1)
		throw "In CLLogger::CLLogger(),open error!";

	logBuffer = new char[BUFFER_SIZE_LOG_FILE];
	usedByteForBuffer = 0;
	
	flagForProcessExit = false;

	mutexForWriteingLog = new pthread_mutex_t;
	if(pthread_mutex_init(mutexForWriteingLog,0) != 0){
		delete mutexForWriteingLog;
		delete []logBuffer;
		close(fileFd);

		throw "In CLLogger::CLLogger(),pthread_mutex_init error!";
	}
}

CLLogger::~CLLogger(){
	if(fileFd != -1){
		close(fileFd);
	}
}

CLLogger* CLLogger::getInstance(){
	if(logObj == NULL){
		logObj = new CLLogger();
		if(atexit(CLLogger::onProcessExit) != 0){
			if(logObj != NULL){
				logObj->writeLog("In CLLogger::getInstance(), atexit error!",errno);
				logObj->flush();
			}
		}
	}

	return logObj;
}

void CLLogger::onProcessExit(){
	CLLogger *logger = CLLogger::getInstance();
	cout << "before exit we will invoke the flush function" << endl;
	if( logger != 0 )
		logger->flush();
}

CLStatus CLLogger::writeLog(const char *msg, long errorCode){
	if(msg == 0)
		return CLStatus(-1,0);
	
	if(strlen(msg) == 0)
		return CLStatus(-1,0);
	
	if(fileFd == -1)
		return CLStatus(-1,0);
	
	//带缓冲区的日志类代码实现
	unsigned int nLeftRoom = BUFFER_SIZE_LOG_FILE - usedByteForBuffer;

	unsigned int lengthOfMsg = strlen(msg);

	char buf[MAX_LINE];
	snprintf(buf,MAX_LINE," Error code:%d\r\n",errorCode);
	unsigned int lengthOfCode = strlen(buf);

	unsigned int totalLen = lengthOfMsg + lengthOfCode;
	if(totalLen > BUFFER_SIZE_LOG_FILE){
		CLStatus s = flush();
		if(!s.isSuccess())
			return CLStatus(-1,0);
	
		ssize_t r = write(fileFd,msg,lengthOfMsg);
		if(r == -1)
			return CLStatus(-1,errno);

		r = write(fileFd,buf,lengthOfCode);
		if(r == -1)
			return CLStatus(-1,errno);
	}

	if(totalLen > nLeftRoom){
		CLStatus s = flush();
		if(!s.isSuccess())
			return CLStatus(-1,0);
	}

	memcpy(logBuffer + usedByteForBuffer,msg,lengthOfMsg);
	usedByteForBuffer += lengthOfMsg;
	memcpy(logBuffer + usedByteForBuffer,buf,lengthOfCode);
	usedByteForBuffer += lengthOfCode;

	/*不带缓冲区的日志类代码实现。
	 * ssize_t n = write(fileFd,msg,strlen(msg));
	if(n < 0)
		return CLStatus(-1,errno);
	
	char buf[MAX_LINE];
	snprintf(buf,MAX_LINE," Error code:%d\r\n",errorCode);

	n = write(fileFd, buf, strlen(buf));
	if(n < 0){
		return CLStatus(-1,errno);
	}*/

	return CLStatus(0,0);
}

CLStatus CLLogger::writeLogMessage(const char *msg, long errorCode){
	CLLogger *log = CLLogger::getInstance();
	if(log == 0)
		return CLStatus(0,0);
	
	CLStatus s = log->writeLog(msg,errorCode);
	if(s.isSuccess())
		return CLStatus(0,0);
	else
		return CLStatus(-1,0);
}

CLStatus CLLogger::flush(){
	if(pthread_mutex_lock(mutexForWriteingLog) != 0)
		return CLStatus(-1,0);
	
	try{
		if(usedByteForBuffer == 0)
			throw CLStatus(0,0);

		if(write(fileFd,logBuffer,usedByteForBuffer) == -1)
			throw CLStatus(-1,errno);

		usedByteForBuffer = 0;
		throw CLStatus(0,0);
	}catch(CLStatus &s){
		if(pthread_mutex_unlock(mutexForWriteingLog) != 0)
			return CLStatus(-1,0);

			return s;
	}

}
