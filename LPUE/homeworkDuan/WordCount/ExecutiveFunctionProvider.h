#ifndef EXECUTIVEFUNCTIONPROVIDER_H_
#define EXECUTIVEFUNCTIONPROVIDER_H_

class ExecutiveFunctionProvider{
public:
    ExecutiveFunctionProvider();
    virtual ~ExecutiveFunctionProvider();

public:
    virtual int runExecutiveFunction( void *pContext ) = 0;

private:
    ExecutiveFunctionProvider( const ExecutiveFunctionProvider& );
    ExecutiveFunctionProvider& operator=( const ExecutiveFunctionProvider& );
};

#endif
