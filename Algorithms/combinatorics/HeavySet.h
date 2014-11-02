#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long data_type;

data_type factorial( data_type n){
    data_type result = 1;
    while( n != 0){
        result *= n;
        n--;
    }

    return result;
}

data_type F(data_type n , data_type r ){
    return factorial(n + r - 1) /( factorial(r) * factorial( n-1 ));
}

data_type heavySet(data_type n, data_type r , data_type[] coefficient){
    data_type sum = 0;
    data_type val;
    data_type count;
    data_type position;
    data_type k;
    data_type R;

    for( data_type i = 0; i < n ; ++i ){
        count = 0;
        position = 0;
        val = i;

        while( val ){
            k = val % 2;
            count += k;
            val = val / 2;
            position++; 
            
            R = coefficient[position] + 1;
        }

        sum += pow( -1, k ) * F( n, R );     
    }

    return sum;
}

