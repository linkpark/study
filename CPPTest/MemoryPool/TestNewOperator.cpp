#include <iostream>
#include <sys/types.h>
#include <exception>
#include <stdlib.h>

using namespace std;

static const int signature = 0xDEADBEEF;
typedef unsigned char Byte;

void *operator new( size_t size ) throw( std::bad_alloc ){
    size_t realSize = size + 2 * sizeof( int );
    
    void *pMem = malloc( realSize );
    if ( !pMem )throw bad_alloc();

    *(static_cast< int* >(pMem) ) = signature
    *(reinterpret_cast< int* >( static_cast< Byte* >( pMem ) + realSize - sizeof( int ) )) = signature;

    return static_cast<Byte*>( pMem ) + sizeof(int);
}
