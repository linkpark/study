#ifndef CLEXECUTIVE_H
#define CLEXECUTIVE_H
#include "stadx.h"
#include "CLExecutiveFunctionProvider.h"

class CLExecutive{
public:
	explicit CLExecutive(CLExecutiveFunctionProvider* pExcutiveFunctionProvider);
	virtual ~CLExecutive();
	
	virtual CLStatus run(void *pContext = 0) = 0;
	virtual CLStatus waitForDeath() = 0;

protected:
	CLExecutiveFunctionProvider *executiveFunctionProvider;
};
#endif 
