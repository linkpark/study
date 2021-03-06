#ifdef GROUPKEYINDEX_H_
#define GROUPKEYINDEX_H_
#include "ColumnIndexBase.h"

class MainData;
class DeltaData;

template <class T>
class GroupKeyIndex public ColumnIndexBase<T>{
public:
    virtual string searchByKey(T &key);
    virtual vector<T> searchByKeyRange();

private:
    int mergeProcess();

private:
    MainData m_CMainData;
    DeltaData m_CDeltaData;
};
#endif

