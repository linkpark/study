#ifndef PROCESS_H_
#define PROCESS_H_
#include <sys/types.h>
#include "Executive.h"
#include "ExecutiveFunctionProvider.h"

class Process:public Executive{
public:
    explicit Process(ExecutiveFunctionProvider *pFunctionProvider);
    virtual ~Process();
    
    virtual int run(void *pStrCmdLine) = 0;
    virtual int waitForDeath();

private:
    Process(const Process& );
    const Process& operator=(Process&);

private:
    pid_t m_ProcessId;

    bool m_bProcessCreated;
    bool m_bWaitForDeath;
    bool m_bExecSuccess;
};

#endif 
