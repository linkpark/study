#ifndef ABSTRACTATTRIBUTEVECTOR_H_
#define ABSTRACTATTRIBUTEVECTOR_H_
#include <cstddef>
#include <cstdint>

class AbstractAttributeVector{
public:
    virtual ~AbstractAttributeVector();
    virtual uint64_t getColumns()const = 0;
};

#endif
