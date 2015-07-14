#include <iostream>
#include <boost/atomic.hpp>

/*在编译时需要链接原子库-lboost_atomic*/

using namespace std;

int main() {
    boost::atomic<bool> b(false); 
    assert(!b.load());

    b.store(true);
    assert(b);
    auto a = 3;
}


