#include <iostream>
#include <stdlib.h>

using namespace std;

class SimpleMempool{
public:
    SimpleMempool(size_t size):isUsed_(false), size_(size){
        pBuf_ = malloc( size_ );
    }

    ~SimpleMempool(){
        free( pBuf_ );
        cout << "delete buffer " <<endl;
    }

    void freeBuf(){
        isUsed_ = false;
    }

    void *allocBuf(){
        if( isUsed_ == true )
            return NULL;

        isUsed_ = true;
        return pBuf_;
    }

private:
    bool isUsed_; 
    void *pBuf_;
    size_t size_;
};

class TestClass{
public:
    TestClass(){
    }
    ~TestClass(){}

public:
    void set( int a ){
        a_ = a;
    }
    void toString(){
        cout << "Hello world " << a_ << endl;
    }

    void* operator new( size_t size , SimpleMempool *mempool );
    void operator delete( void *pBuf , SimpleMempool *mempool );
    void* operator new( size_t size);
    void operator delete( void *pBuf );
private:
    int a_;

};

SimpleMempool mempool( sizeof(TestClass) );

void* TestClass::operator new( size_t size ){
        return mempool.allocBuf();
}

void TestClass::operator delete( void *pBuf ){
        return mempool.freeBuf();
}


void* TestClass::operator new( size_t size, SimpleMempool* mempool ){
    if( mempool == NULL )
        return ::operator new( size );
    else
        return mempool->allocBuf();
}

void TestClass::operator delete( void *pBuf, SimpleMempool* mempool ){
    if( mempool == NULL )
        return ::operator delete( pBuf );
    else
        return mempool->freeBuf();
}

int main(){
    cout << sizeof( TestClass) <<endl;
    TestClass *test = new (&mempool)TestClass(  );
    test->set(1);
    TestClass *test2 = new TestClass(  );
    test->toString();
    if( test2 == NULL ){
        cout << "Mempool is busy " <<endl;
    }
    
    test2 = new TestClass( );
    if(NULL != test2 ) {
        test2->set(2);
        test2->toString();
    }

    return 0;
}

