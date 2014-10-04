#ifndef MAINDATA_H_
#define MAINDATA_H_
#include <vector>
#include <map>
#include <string>
using namespace std;

class MainData{
public:
    vector< string >& getDic();
    vector< int >& getPositionVector();
    vector< int >& getIndexVector(); 
    vector< int >& setPositionVector();
    vector< int >& setIndexVector();

private:
    vector< int > m_vIndexVector;
    vector< int > m_vPositionVector;
    vector< string > m_vDic;   
};

#endif
