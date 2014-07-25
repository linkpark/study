#ifndef CLSTATUS_H
#define CLSTATUS_H
#include "stadx.h"
class CLStatus{
	private:
		long returnCode;
		long errorCode;

	public:
		CLStatus(long returnCodeParam , long errorCodeParam);
		CLStatus(const CLStatus &s);
		virtual ~CLStatus();

		const long& constReturnCode;
		const long& constErrorCode;		                           
	public:
		bool isSuccess();
};

#endif

