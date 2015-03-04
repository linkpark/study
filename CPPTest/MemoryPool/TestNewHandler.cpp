#include <iostream>
#include <stdlib.h>
#include <sys/types.h>

using namespace std;

void outOfMem(){
    cerr << "Unable to satisfy request for memory, I can't alloca any more" <<endl;
    abort();
}

class X {
public:
    static void outOfMem();

    void* operator new(size_t size){
        std::set_new_handler( outOfMem ); 
        return ::operator new(size); 
    }

private:
    int a[100000000000000000ull];
};

class Y {
public:
    static void outOfMem();

    void* operator new(size_t size){
        std::set_new_handler( outOfMem ); 
        return ::operator new(size); 
    }

private:
    int a[100000000000000000ull];
};

void X::outOfMem(){
    cerr << "In class X::Unable to satisfy request for memory!" <<endl;
    abort();
}

void Y::outOfMem(){
    cerr << "In class Y::Unable to satisfy request for memory!" <<endl;
    abort();
}

int main( void ){
    Y *y = new Y();
    X *x = new X();

    return 0;
}
