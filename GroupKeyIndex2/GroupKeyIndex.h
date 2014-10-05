#ifdef GROUPKEYINDEX_H_
#define GROUPKEYINDEX_H_
#include "ColumnIndexBase.h"

class MainData;
class DeltaData;

template <class T>
class GroupKeyIndex final:public ColumnIndexBase<T>{
public:
    vector<uint64_t> searchByKey( T &key );
    vector<uint64_t> searchByKeyRange( T &start, T &end );
    
    batchImport( vector<T> &dataList );

    T searchByRowId( uint64_t rowId );

public:
    GroupKeyIndex();
    ~GroupKeyIndex();

//forbidden copy constructe function
private:
    GroupKeyIndex(const GroupKeyIndex<T>&);
    GroupKeyIndex<T>& operator=(const GroupKeyIndex<T>&);
    
private:
    int mergeProcess();

private:
    MainData m_CMainData;
    DeltaData m_CDeltaData;
};
#endif

