#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int i,n;
    long long *number;
    
    cin >> n;
    number = new long long[n + 1];
    number[0] = 0;
    number[1] = 1;
    
    for(i = 2; i <= n; i ++){
        number[i] = number[i-1] + number[i-2]; 
    }

    cout << "the " << n << "st Fibonacci cut sequence number is:" << number[n] << endl;
    delete[] number;

    return 0;
}
