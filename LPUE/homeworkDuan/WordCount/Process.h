#ifndef PROCESS_H_
#define PROCESS_H_
#include "Executive.h"
#include "ExecutiveFunctionProvider.h"

class Process:public Executive{
public:
    explicit Process(ExecutiveFunctionProvider *pFunctionProvider);
    virtual ~Process();
    
    virtual run(void *pstrCmdLine) = 0;
    virtual waitForDeath();

private:
    Process(const Process& );
    const Process& operator=(Process&);

    pid_t m_ProcessId;

    bool m_bProcessCreated;
    bool m_bWaitForDeath;
    bool m_bExecSuccess;
};

#endif 
