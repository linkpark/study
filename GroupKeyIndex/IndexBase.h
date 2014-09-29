#ifdef INDEXBASE_H_
#define INDEXBASE_H_
#include <string>
#include <vector>

using namespace std;

template <class T>
class IndexBase{
public:
    virtual string searchByKey(T &key) = 0;
    virtual vector< string > searchByKeyRange(T &start, T &end) = 0;
};

#endif

