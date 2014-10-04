#ifndef BASEATTRIBUTEVECTOR_H_
#define BASEATTRIBUTEVECTOR_H_
#include <sys/types.h>

//compressed vector interface
template <class T>
class BaseAttributeVector{
public:
    virtual ~BaseAttributeVector(){}
    
/*interface list*/
public:
    virtual void resize(size_t size) = 0;

    /*provide the base get and set function*/
    virtual T get(size_t row) = 0;
    virtual void set(size_t row,T &value) =0;
    
    /*get the size of an object*/
    virtual size_t getSize()const = 0; 
};

#endif
