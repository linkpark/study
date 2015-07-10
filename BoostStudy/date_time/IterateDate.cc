#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;

int main() {
    boost::gregorian::date d1(2008,11,20);

    boost::gregorian::date d_start(d1.year(),d1.month(),1);
    boost::gregorian::date d_end( d1.end_of_month() );

    for( boost::gregorian::day_iterator d_iter(d_start);
            d_iter != d_end; ++d_iter ) {
        cout << *d_iter << " " << d_iter->day_of_week() << endl;
    }

    return 0;
}
