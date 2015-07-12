#include <boost/smart_ptr.hpp>
#include <iostream>
#include <assert.h>

using namespace std;

int main() {
    boost::shared_ptr<int> sp( new int(100) );
    
    cout << sp.use_count() << endl;

    boost::weak_ptr<int> wp(sp);

    cout << wp.use_count() << endl;

    if(!wp.expired() ) {
        boost::shared_ptr<int> sp2 = wp.lock();
        *sp2 = 100;
        cout << wp.use_count() <<endl;
    }

    cout << wp.use_count() << endl;
    sp.reset();
    cout << wp.expired() <<endl;
    assert(wp.lock());
} 

