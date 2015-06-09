#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

//计算一个二进制数中1的个数
int caculateNumberOfOne( int number , int bitWidth ) {
    int count = 0;
    
    for( int i = 0; i < bitWidth; ++i ) {
        if( number & ( 1ull << i ) ){
            count ++;
        } 
    }     

    return count;
}

int main(){
    int n,q,m;

    cin >> n >> m >> q;
    
    int w[n];    

    for( int i = 0; i < n ; ++ i ) {
        cin >> w[i];
    }

    const int maxState = (1 << (m -1) ) - 1 ;

    int best[n][ maxState + 1 ];    
    
    for( int i = 0; i < n; ++ i ) {
        for( int j = 0; j < maxState + 1; ++ j ){
            best[i][j] = -1;
        }
    } 


    best[0][0] = 0;
    best[0][1] = w[0];

    //状态递推去求解
    for( int i = 0; i < n - 1 ; ++ i ) {
        for( int s = 0 ; s <= maxState ; ++s ) {
            int c = caculateNumberOfOne( s , m);
            if( best[i][s] != -1 ) {
                int not_choose = (s << 1) & maxState;
                int choose = not_choose | 1;
            
                best[i+1][ not_choose ] = max(best[i+1][not_choose],best[i][s]);
                if( c < q ){
                    //choose the (i+1)th seat
                    best[i+1][ choose ] = max( best[i+1][choose],best[i][s] + w[i+1]);
                }
            }
        }
    } 
        
    int result = 0;

    for( int s = 0 ; s <= maxState ; ++ s ){
        if( best[n - 1 ][s] > result ) {
            result = best[n-1][s];
        }
    }

    cout << result <<endl;

    return 0; 
}
