#ifndef CACHEBLOCKINTERFACE_H_ 
#define CACHEBLOCKINTERFACE_H_
#include <sys/types.h>

class CacheBlockInterface{
public:
    CacheBlockInterface(){}
    virtual ~CacheBlockInterface(){}

/*
 *define the interface of the block class 
 * */
public:
    virtual int setCacheValue(void *buf,size_t n) = 0;
    virtual int getCacheValue(void *buf,size_t n, size_t offset) = 0;
};

#endif 
