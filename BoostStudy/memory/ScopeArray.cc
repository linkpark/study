#include <boost/smart_ptr.hpp>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    boost::scoped_array<int> sa( new int[100] );
    
    //填充数组
    fill_n(&sa[0],100,5);
    sa[10] = sa[20] + sa[30];

    cout << sa[10] <<endl; 

    return 0;
}
