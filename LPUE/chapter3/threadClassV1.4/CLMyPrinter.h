#ifndef CLMYPRINTER_H
#define CLMYPRINTER_H
#include "CLExecutiveFunctionProvider.h"
class CLMyPrinter:public CLExecutiveFunctionProvider{
public:
	CLMyPrinter(){}
	~CLMyPrinter(){}

	virtual CLStatus runExecutiveFunction(void *contextParam){
		if(contextParam == NULL)
			return CLStatus(-1,0);
		cout << "the thread is running" <<endl;
		
		return CLStatus(0,0);
	}
};
#endif
