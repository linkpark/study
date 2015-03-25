//this is the version of memory leak
//too much memory cost;
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

long long best[502][100002]= {{0}};

int main(){
    long long n,m;
    long long value[ 502 ];
    long long need [ 502 ];

    scanf( "%lld %lld", &n, &m );

    for( long long i = 1 ; i <= n ; ++i ){
        scanf( "%lld %lld", &need[i], &value[i] );
    }
    
    for( long long i = 1; i <= n ; ++i ){
        for( long long j = 0; j <=m ; ++j ){
            if( need[i] > j ){
                best[i][j] = best[i - 1][j];
            }else{
                best[i][j] = max(best[i-1][j], (best[i-1][j-need[i]] + value[i]));
            }
        }
    }

    cout << best[n][m] << endl;
    
    return 0;
}

