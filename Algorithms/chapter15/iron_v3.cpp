#include <iostream>
#include <cstdio>

using namespace std;

int price[1000] = {0,1,5,8,9,10,17,17,20,24,30};

int cutRod(int length,int *r,int *s){
    r[0] = 0;
    s[0] = 0;
    int q,i,j;
    if( 0 == length){
        return 0;
    }
    
    for(i = 1 ; i <= length ; i++){
        q = -1;
        for(j = 1 ; j <= i ; j ++){
            if( q < price[j] + r[i - j]){
                q = price[j] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = q;
    }
    
    return r[length];
}

int main(){
    int ironLength;
    int *r,*s; 
    
    cin >> ironLength;
    r = new int[ironLength + 2];
    s = new int[ironLength + 2];
    
    cout << "the best profit is " << cutRod( ironLength, r ,s) << endl; 
    cout << "the best plan is:";
    while(ironLength > 0){
        cout << s[ironLength] << " ";
        ironLength = ironLength - s[ironLength];
    }

    cout << endl;
    delete[] r;
    delete[] s;
    return 0;
}

