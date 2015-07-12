#include <iostream>
#include <boost/smart_ptr.hpp>

using namespace std;

//use weak_ptr to deal with the circle reference;

class node {
public:
    ~node () {
        cout << "deleted " <<endl;
    }

    node() { }

   // typedef boost::shared_ptr<node> ptr_type;
    typedef boost::weak_ptr<node> ptr_type;
    ptr_type next;
};

int main() {
    auto p1 = boost::make_shared<node>();
    auto p2 = boost::make_shared<node>();

    p1->next = p2;
    p2->next = p1;

    cout << p1.use_count() <<endl;
    cout << p2.use_count() <<endl;

    if( !p1->next.expired() ) {
        auto p3 = p1->next.lock();
    }

    return 0;
}

