#ifndef CLEXECUTIVEFUNCTIONPROVIDER_H
#define CLEXECUTIVEFUNCTIONPROVIDER_H
#include "stadx.h"
#include "CLStatus.h"
#include "CLLogger.h"

class CLExecutiveFunctionProvider{
public:
	CLExecutiveFunctionProvider();
	virtual ~CLExecutiveFunctionProvider();

public:
	virtual CLStatus runExecutiveFunction(void *pContext) = 0;
};

#endif
