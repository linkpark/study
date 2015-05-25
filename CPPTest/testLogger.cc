#include <iostream>

using namespace std;

void function(){
    cout << __PRETTY_FUNCTION__ <<endl;
}

int main(){
    cout << "In " <<__FILE__<<":"<<__LINE__<<":"<< __PRETTY_FUNCTION__ <<endl;
    function();

    return 0;
}
