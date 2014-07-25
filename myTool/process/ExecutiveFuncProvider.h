/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-17 14:17
#
# Filename: ExecutiveFuncProvider.h
#
# Description: 
#
=============================================================================*/
#ifndef EXECUTIVEFUNCPROVIDER_H_
#define EXECUTIVEFUNCPROVIDER_H_

class ExecutiveFuncProvider{
public:
    ExecutiveFuncProvider();
    virtual ~ExecutiveFuncProvider();

public:
    virtual int runExecutiveFunc( void *pContext ) = 0;

private:
    ExecutiveFuncProvider( const ExecutiveFuncProvider& );
    ExecutiveFuncProvider& operator=( const ExecutiveFuncProvider& );
};

#endif 
