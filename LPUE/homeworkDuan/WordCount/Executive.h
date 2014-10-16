#ifndef EXECUTIVE_H_
#define EXECUTIVE_H_
class ExecutiveFunctionProvider;
class Executive{
public:
    explicit Executive(ExecutiveFunctionProvider *pFunctionProvider);
    virtual ~Executive();
    
    virtual int run( void *pContext ) = 0;
    virtual int waitForDeath() = 0;

protected:
    ExecutiveFunctionProvider *m_pFunctionProvider;

private:
    Executive( const Executive& );
    Executive& operator=( const Executive& );
};
#endif
