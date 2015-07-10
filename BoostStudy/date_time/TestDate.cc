#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>

using namespace std;

/*
 * 在编译时，需要增加编译选项-lboost_date_time
 *
 * */
int main(){
    boost::gregorian::date d1(2010,1,30);
    string date_string = boost::gregorian::to_simple_string(d1);

    cout << d1 << endl;
    cout << date_string << endl;
    cout << boost::gregorian::day_clock::local_day() <<endl;
    
    return 0;
}
