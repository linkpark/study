#include <boost/smart_ptr.hpp>
#include <iostream>
#include <algorithm>

using namespace std;

class Shared { 
public:
    Shared(boost::shared_ptr<int> p ):p_(p) {}
    ~Shared(){}

    void Print(){
        cout << "count" << p_.use_count() << "v=" << *p_ <<endl; 
    }

private:
    boost::shared_ptr<int> p_;
};

void print_func(boost::shared_ptr<int> &p ) {
    cout << "count " << p.use_count() << " v=" << *p<< endl;
}

int main(){
    boost::shared_ptr<int> p(new int(100));
    Shared s1(p),s2(p);

    s1.Print();
    s2.Print();

    *p = 20;
    print_func(p);

    s1.Print();
}
