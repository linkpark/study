#include <iostream>
#include <stdio.h>

using namespace std;

//计算一个二进制数中1的个数
int caculateNumberOfOne( unsigned short number ) {
    int count = 0;

    while( number ) {
        if( number & 0x0001 ) 
            ++count;
        
        number = number >> 1;
    }

    return count;
}

void addOneInTheEnd ( unsigned short &number ) {
    number = number << 1;
    number = number | 0x0001;    
}

void addZeroInTheEnd ( unsigned short &number ) {
    number = number << 1;
}

int main(){
    int n,q;
    unsigned short m;

    int w[1002];
    int best[1002][2049];

    cin >> n;
    cin >> m;
    cin >> q;
    
    
    best[0][0] = 0;

    for( int i = 0; i < n ; ++ i ) {
        cin >> w[i];
    }

    for( int i = 0; i < n ; ++ i ) {
        best[i][]
    } 

    return 0; 
}
