#include "stadx.h"
#include "CLThread.h"
#include "CLParaPrinter.h"

int main(){
	CLExecutiveFunctionProvider *printer = new CLParaPrinter();
	CLExecutive *pThread = new CLThread(printer);
	
	pThread->run((void*)2);
	pThread->waitForDeath();
	 
	return 0;
}
