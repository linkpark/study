#include <iostream>
#include <boost/signals2.hpp>

//signal 函数模板的命名空间在signals2

using namespace std;

void slots1() {
    cout << " slot1 called " << endl;
}

void slots2() {
    cout << " slot2 called " << endl;
}

int main() { 
    boost::signals2::signal<void()> sig;

    sig.connect(&slots1);
    sig.connect(&slots2);

    sig();

    return 0;
}
