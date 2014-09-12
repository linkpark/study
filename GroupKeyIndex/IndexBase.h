#ifdef INDEXBASE_H_
#define INDEXBASE_H_
#include <string>
#include <vector>

using namespace std;

class IndexBase{
public:
    virtual string searchByKey(string &key) = 0;
    virtual vector< string > searchByKeyRange(string &start, string &end) = 0;
};

#endif

