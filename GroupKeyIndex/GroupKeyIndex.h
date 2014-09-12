#ifdef GROUPKEYINDEX_H_
#define GROUPKEYINDEX_H_
#include "IndexBase.h"

class MainData;
class DeltaData;
class GroupKeyIndex public IndexBase{
public:
    virtual string searchByKey(string &key);
    virtual vector<string> searchByKeyRange();

private:
    int mergeProcess();

private:
    MainData m_CMainData;
    DeltaData m_CDeltaData;
};
#endif

