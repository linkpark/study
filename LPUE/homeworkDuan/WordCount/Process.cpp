#include "Process.h"

Process::Process(ExecutiveFunctionProvider *pFunctionProvider):Executive(pFunctionProvider){
    m_bProcessCreated = false;
    m_bWaitForDeath = false;
    m_bExecSuccess = true;
}
