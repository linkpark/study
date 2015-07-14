#include <boost/thread.hpp>
#include <iostream>

using namespace std;

void dummy( int n ) {
    for( int i = 0 ; i < n ; ++i ) {
        cout << i <<endl;
    }
}

int main() { 
    boost::thread t1(dummy, 100 );
    boost::thread t2(dummy, 500 );

    boost::chrono::milliseconds dura(2000);

    boost::this_thread::sleep_for(dura);
    //t1.join();
    //t2.join();

    k
    return 0;
}
