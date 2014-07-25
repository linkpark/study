#ifndef CLEXECUTIVE_H
#define CLEXECUTIVE_H
#include "stadx.h"
#include "CLCoordinator.h"

class CLExecutive{
public:
	explicit CLExecutive(CLCoordinator *coordinatorParam):coordinator(coordinatorParam){
	}

	virtual ~CLExecutive(){
	}
	
	virtual CLStatus run() = 0;
	virtual CLStatus waitForDeath() = 0;

protected:
	CLCoordinator *coordinator;
};

#endif 
