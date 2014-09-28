#ifndef SIMPLECACHEBLOCK_H_
#define SIMPLECACHEBLOCK_H_
#include "CacheBlockInterface.h"

class SimpleCacheBlock final:public CacheBlockInterface{
public:
    SimpleCacheBlock(int Size):m_iSize(Size){
        m_pCache = new char[m_iSize];
    }

    ~SimpleCacheBlock(){
        if(nullptr != m_pCache)
            delete [] m_pCache;
    }

    int setCacheValue(void *buf,size_t n);
    int getCacheValue(void *buf,size_t n, size_t offset);

private:
    int m_iSize;
    char *m_pCache;
};

#endif
