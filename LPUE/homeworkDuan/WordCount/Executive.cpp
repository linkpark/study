#include "ExecutiveFunctionProvider.h"
#include "Executive.h"

Executive::Executive(ExecutiveFunctionProvider *pFunctionProvider):
    m_pFunctionProvider(pFunctionProvider){
    if( 0 == m_pFunctionProvider){
        throw "in Executive::Executive, ExecutiveFunctionProvider error!";
    }
}

Executive::~Executive(){
}
