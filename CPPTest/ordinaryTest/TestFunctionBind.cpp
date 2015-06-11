#include <iostream>
#include <cstdio>
#include <tr1/functional>

using namespace std;

void func( int x , int y ) {
    cout << x << " " << y <<endl;
}

int main(){

    std::tr1::bind<int>(func, 3, _1 );

    return 0;
}
