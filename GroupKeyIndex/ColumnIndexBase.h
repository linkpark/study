#ifdef COLUMNINDEXBASE_H_
#define COLUMNINDEXBASE_H_
#include <string>
#include <vector>

using namespace std;

template <class T>
class ColumnIndexBase{
public:
    virtual string searchByKey(T &key) = 0;
    virtual vector< string > searchByKeyRange(T &start, T &end) = 0;
    virtual batchImport(vector<T> &dataList) = 0;
};

#endif

