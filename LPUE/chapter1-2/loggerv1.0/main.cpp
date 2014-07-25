#include "CLLogger.h"

CLStatus f(){
	return CLStatus(-1,4);
}

int main(){
	CLStatus s = f();
	if(!s.isSuccess()){
		CLLogger::writeLogMessage("this is an error!",s.constErrorCode);
	}

	return 0;
}
