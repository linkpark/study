#ifndef ABSTRACTATTRIBUTEVECTOR_H_
#define ABSTRACTATTRIBUTEVECTOR_H_

#ifndef uint64_t 
typedef unsigned long long uint64_t;
#endif

class AbstractAttributeVector{
public:
    virtual ~AbstractAttributeVector();
    virtual uint64_t getColumns()const = 0;
};

#endif
