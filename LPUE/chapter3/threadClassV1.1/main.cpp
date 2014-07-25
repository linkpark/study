#include "stadx.h"
#include "CLThread.h"
#include "CLMyThread.h"

int main(){
	CLThread *pthread = new CLMyThread();
	int a = 5;

	pthread->run((void*)&a);
	pthread->waitForDeath();
	return 0;
}
