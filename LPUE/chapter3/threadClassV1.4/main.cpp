#include "stadx.h"
#include "CLRegularCoordinator.h"
#include "CLMyPrinter.h"

int main(int argc,char **argv){
	CLCoordinator *pCoordinator = new CLRegularCoordinator();
	CLExecutive *pExecutive = new CLThread(pCoordinator);
	CLExecutiveFunctionProvider *pProvider = new CLMyPrinter();

	pCoordinator-> setExecObjects(pExecutive,pProvider);
	
	pCoordinator-> run((void*)5);
	
	pCoordinator-> waitForDeath();
	
	return 0;		
}
