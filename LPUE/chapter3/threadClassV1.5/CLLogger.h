#ifndef CLLOGGER_H
#define CLLOGGER_H
#include "stadx.h"
#include "CLStatus.h"

#define LOG_FILE_NAME "log.txt"
#define MAX_LINE 256
#define BUFFER_SIZE_LOG_FILE 1024
class CLLogger{
	public:
		static CLLogger* getInstance();
		CLStatus writeLog(const char *msg, long errorCode);
		static CLStatus writeLogMessage(const char *msg, long errorCode);
		CLStatus flush();
				
	private:
		CLLogger();
		CLLogger& operator=(const CLLogger&);
		
		CLLogger(const CLLogger&);
		~CLLogger();

		static void onProcessExit();
		
		static pthread_mutext_t *initializeMutex();
		CLStatus writeMsgAndErrCodeToFile(const char *pstrMsg,const char *pstrErrCode);

	private:
		int fileFd;
		static CLLogger* logObj;
		char *logBuffer;
		unsigned int usedByteForBuffer;	
		bool flagForProcessExit;
		pthread_mutex_t *mutexForWriteingLog;
		static pthread_mutext_t *mutexForCreatingLogger;
};
#endif
