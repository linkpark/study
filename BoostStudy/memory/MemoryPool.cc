#define BOOST_SYSTEM_NO_DEPRECATED
#include <boost/pool/pool.hpp>
#include <iostream>

using namespace std;

int main() {
    boost::pool<> pl(sizeof(int));

    int *p = static_cast<int*>(pl.malloc());
    assert(pl.is_from(p));

    pl.free(p);

    for(int i = 0; i < 100 ; ++i ) {
        pl.ordered_malloc(10);
    }
}
