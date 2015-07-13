#include <iostream>
#include <boost/signals2.hpp>

using namespace std;

template<int N>
struct slots{
    int operator() (int x) {
        cout << "slot" <<N << " called" <<endl;
        return x * N;
    }
};

int main() { 
    boost::signals2::signal<int (int )> sig;
    sig.connect(slots<10>());
    sig.connect(slots<20>());

    cout << *sig(2)<<endl;
}
