#include "CLRegularCoordinator.h"
CLStatus CLRegularCoordinator::run(void *contextParam){
	if((executive == 0) || (provider == 0) )
		return CLStatus(-1,0);
	context = contextParam;
	
	return executive->run();	
}

CLStatus CLRegularCoordinator::returnControlRights(){
	return provider->runExcutiveFunction(context);
}

CLStatus CLRegularCoordinator::waitForDeath(){
	return executive->waitForDeath();
}

