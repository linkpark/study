#include <boost/timer.hpp>
#include <iostream>

using namespace boost;
using namespace std;

int main(){
    boost::timer t;

    cout << "max timespan:" << t.elapsed_min() << endl;

    cout << "now time elapse " << t.elapsed() << "s" << endl;

    return 0;
}

