#ifndef CACHEMANAGE_H_
#define CACHEMANAGE_H_
#include <map>

using namespace std;

class CacheBlock;
class CacheManager{
public:
    CacheManager(int cacheBlockNumber);
    ~CacheManager();

private:
    int m_iCacheBlockNumber;
    map<int,CacheBlock>     
};
#endif
