#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//建立分支预测
#define likely(x) __builtin_expect(!!(x),1)
#define unlikely(x) __builtin_expect(!!(x),0)

using namespace std;

int main( int argc, char **argv ) {
    int a;
    a = atoi( argv[1] );
    if(unlikely(!a) )
       a++;
    else
       a--;

   cout << a <<endl; 
   return 0;
}
