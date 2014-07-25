#include "stadx.h"
#include "CLThread.h"

int main(){
	CLThread pthread;
	int a = 5;

	pthread.run((void*)&a);
	pthread.waitForDeath();
	return 0;
}
