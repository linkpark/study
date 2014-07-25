#ifndef CLCOORDINATOR_H
#define CLCOORDINATOR_H
#include "stadx.h"
#include "CLExecutive.h"
#include "CLExecutiveFunctionProvider.h"
#include "CLStatus.h"
#include "CLLogger.h"

class CLCoordinator{
public:
	CLCoordinator(){}
	virtual ~CLCoordinator(){}

	void setExecObjects(CLExecutive *executiveParam,CLExecutiveFunctionProvider *providerParam){
		executive = executiveParam;
		provider = providerParam;
	}

	virtual CLStatus run(void *contextParam) = 0;
	virtual CLStatus returnControlRights() = 0;
	virtual CLStatus waitForDeath() = 0;

protected:
	CLExecutive *executive;
	CLExecutiveFunctionProvider *provider;
	void *context;
};

#endif
