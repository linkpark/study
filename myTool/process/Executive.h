/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-17 14:17
#
# Filename: Executive.h
#
# Description: 
#
=============================================================================*/
#ifndef EXECUTIVE_H_
#define EXECUTIVE_H_

class ExecutiveFuncProvider;
class Executive{
public:
    explicit Executive( ExecutiveFuncProvider *pExecutiveFuncProvider);
    virtual ~Executive();

public:
    virtual int run(void *pContext = 0 ) = 0;
    virtual int waitForDeath() = 0;

    ExecutiveFuncProvider* getExecutiveFuncHandler()const;

private:
    ExecutiveFuncProvider *m_pExecutiveFuncProvider;

private:
    Executive( const Executive& cExecutive);
    Executive& operator=(const Executive& ); 
};

#endif

