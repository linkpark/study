#ifndef CLREGULARCOORDINATOR_H
#define CLREGULARCOORDINATOR_H
#include "CLCoordinator.h"
class CLRegularCoordinator:public CLCoordinator{
public:
	CLStatus run(void *contextParam);
	CLStatus returnControlRights();
	CLStatus waitForDeath();
};

#endif
