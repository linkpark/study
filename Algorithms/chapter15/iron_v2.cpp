/*在分治的基础上增加记忆子任务，用以提高算法的执行效率*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int price[1000] = {0,1,5,8,9,10,17,17,20,24,30};

int cutRod(int length,int *r){
    if(r[ length ] > 0){
        return r[ length ];
    }

    if( 0 == length){
        return 0;
    }
    
    int q = -1;

    for(int i = 1; i <= length ; i++){
        q = max(q , price[i]+cutRod( length - i , r) );
    }

    r[ length ] = q;
    
    return q;
}

int main(){
    int ironLength;
    int *r;

    cin >> ironLength;
    r = new int[ ironLength + 2 ];
    for(int j = 0; j < ironLength +2 ; j ++)
        r[j] = -10;

    cout << "the best profit is " << cutRod( ironLength , r) << endl; 

    delete []r;
    return 0;
}

