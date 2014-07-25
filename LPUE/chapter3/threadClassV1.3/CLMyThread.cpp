#include "CLThread.h"

class CLMyThread:public CLThread<CLMyThread>{
public:
	CLStatus runThreadFunction(){
		cout << "the thread is running" <<endl;
		return CLStatus(0,0);
	}
};

int main(){
	CLMyThread thread;
	thread.run((void *)3);
	thread.waitForDeath();

	return 0;
}
