#ifdef COLUMNINDEXBASE_H_
#define COLUMNINDEXBASE_H_
#include <string>
#include <vector>

using namespace std;

template <class T>
class ColumnIndexBase{
public:
    ColumnIndexBase(){}
    virtual ~ColumnIndexBase(){}

public:
    virtual vector< uint64_t > searchByKey( T &key ) = 0;
    virtual vector< uint64_t > searchByKeyRange( T &start, T &end ) = 0;
    virtual batchImport( vector<T> &dataList ) = 0;

    T searchByRowId( uint64_t rowId ) = 0; 
};

#endif

