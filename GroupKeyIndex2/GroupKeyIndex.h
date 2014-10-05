/*
 * =================================================================
 *
 *            Filename:    GroupKeyIndex.h
 *
 *         Description:    group key index class,implement of the group key
 *                         index.
 *             Version:    v1.0
 *             Created:    2014-10-05 11:28
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
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

