#include <tr1/functional>
#include <iostream>

using namespace std;

void function2(int a , int b , int c ) {
    cout << a <<endl;
    cout << b <<endl;
    cout << c <<endl;
}

int main(){
    tr1::function<void (int)> function1;
    function1 = tr1::bind( function2 , tr1::placeholders::_1, 2 , 3 );

    function1(1);

    return 0;
}
