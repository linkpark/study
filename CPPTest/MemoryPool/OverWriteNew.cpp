#include <iostream>
#include <stdlib.h>
#include <sys/types.h>

using namespace std;

class SimpleMemoryPool{
public:
    SimpleMemoryPool( size_t size ):pool_size_( size ), is_used_(false){}

    void* allocMemory( ){
        if(is_used_ == false){
            is_used_ = true;
            return buf_;
        }else
            return NULL;
    }

    void freeMemory(){
        is_used_ = false;
        return; 
    }

    size_t getPoolSize()const{
        return pool_size_;
    }

private:
    size_t pool_size_;
    bool is_used_;
    void *buf_;
};

class TestNew{
public:
    TestNew( SimpleMemoryPool *pool_obj ):number_(0), pool_obj_(pool_obj){}

    void toString(){
        cout << number_ <<endl;
    }

    // @overwrite the new operator
    void* operator new(size_t size){

    }

private:
    int number_;
    SimpleMemoryPool *pool_obj_;
};

void main( void ){

}
