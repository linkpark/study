#include <boost/thread.hpp>

using namespace std;

int main(){
    boost::mutex mu;
    try {
        mu.lock();
        cout << "some operations" <<endl;
        mu.unlock();
    }

    catch(...) {
        mu.unlock();
    }
}
