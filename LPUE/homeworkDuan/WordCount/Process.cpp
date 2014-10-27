#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

#include "Process.h"
#include "Error.h"

using namespace std;

Process::Process(ExecutiveFunctionProvider *pFunctionProvider):Executive(pFunctionProvider){
    m_bProcessCreated = false;
    m_bWaitForDeath = false;
    m_bExecSuccess = true;
}

Process::~Process(){}

int Process::run(void *pStrCmdLine){
    if( false == m_bProcessCreated )
        return FAILED;
    
    m_ProcessId = vfork();

    if(m_ProcessId == 0){
        m_pFunctionProvider -> runExecutiveFunction( pStrCmdLine );
        
        m_bExecSuccess = true;

        _exit(0);
    }else if( m_ProcessId == -1 ){
        cerr << "In Process::run(): vfork error!" <<endl;
        
        delete this;
        
        return FAILED; 
    }else {
        if( !m_bExecSuccess ){
            waitpid( m_ProcessId,0,0 );

            delete this;

            return FAILED;
        }

        m_bProcessCreated = true;

        if(!m_bWaitForDeath)
            delete this;

        return SUCCESSFUL;
    }
}

int Process::waitForDeath(){
    if( !m_bWaitForDeath )
        return FAILED;

    if( !m_bProcessCreated )
        return FAILED;

    if(waitpid(m_ProcessId , 0 , 0) == -1){
        cerr << "In Process::waitForDeath() waitpid error" <<endl;
        return FAILED;
    }

    delete this;

    return SUCCESSFUL; 
}

