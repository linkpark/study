#include <iostream>
#include <cstdio>

using namespace std;

int price[1000] = {0,1,5,8,9,10,17,17,20,24,30};

int cutRod(int length){
    if( 0 == length){
        return 0;
    }
    
    int q = -1;

    for(int i = 1; i <= length ; i++){
        q = max(q , price[i]+cutRod( length - i ) );
    }

    return q;
}

int main(){
    int ironLength;
    
    cin >> ironLength;
    cout << "the best profit is " << cutRod( ironLength ) << endl; 

    return 0;
}
