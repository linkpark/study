#ifndef BASEATTRIBUTEVECTOR_H_
#define BASEATTRIBUTEVECTOR_H_
#include <sys/types.h>
#include "AbstractAttributeVector.h"

template <class T>
class BaseAttributeVector:public AbstractAttributeVector{
public:
    virtual ~BaseAttributeVector(){}
    
/*interface list*/
public:
    virtual uint64_t getColumn()const = 0; 
    virtual void resize(size_t size) = 0;

    /*provide the base get and set function*/
    virtual T get(size_t row,size_t column) = 0;
    virtual uint64_t set(size_t row,size_t column,T &value) =0;
    
    /*get the size of an object*/
    virtual size_t getSize()const = 0; 
};

#endif
