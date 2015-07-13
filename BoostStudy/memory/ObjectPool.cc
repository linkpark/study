/*
 *  需要连接boost系统库：boost_system;
 *  如果在连接时不想加连接选项-lboost_system
 *  需要增加头部定义#define BOOST_SYSTEM_NO_DEPRECATED
 * */
#include <boost/pool/object_pool.hpp>
#include <iostream>

using namespace std;

class demo_class{
public:
    int a,b,c;
    demo_class(int x = 1, int y = 2, int z = 3 ):a(x),b(y),c(z) { }

    ~demo_class() { cout << "the class has been deleted " <<endl; }
};

int main(){
    boost::object_pool< demo_class > pl;

    auto p = pl.malloc();
    assert(pl.is_from(p));

    p = pl.construct(7,8,9);
    cout << p->a <<endl;
}

