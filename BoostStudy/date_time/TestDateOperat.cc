#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;


int main(){
    boost::gregorian::date d1(2010,1,30);
    boost::gregorian::date d2(2013,1,3);

    cout << d2 - d1 << "days" << endl;
    
    d1 += boost::gregorian::days(10);
    cout << d1 << endl;

    d1 += boost::gregorian::weeks(1);
    cout << d1 <<endl;

    d1 += boost::gregorian::months(1);
    cout << d1 <<endl;

    return 0;
}

