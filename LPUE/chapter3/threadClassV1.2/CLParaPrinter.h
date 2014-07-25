#ifndef CLPARAPRINTER_H
#define CLPARAPRINTER_H
#include "stadx.h"
#include "CLExecutiveFunctionProvider.h"

class CLParaPrinter:public CLExecutiveFunctionProvider{
public:
	CLParaPrinter();
	virtual ~CLParaPrinter();
	
	virtual CLStatus runExecutiveFunction(void *pContext){
		cout << "the thread is running" <<endl;
		return CLStatus(0,0);
	}
};

#endif
