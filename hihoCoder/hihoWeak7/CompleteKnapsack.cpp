#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

long long best1[100002];
long long best2[100002];

int main(){
    long long n, m;
    long long value[502];
    long long need[502];

    scanf("%lld %lld",&n,&m);

    for( long long i = 1 ; i <= n ; ++i ){
        scanf("%lld %lld", &need[i], &value[i] );
    }  

    for( long long i = 1 ; i <= n ; ++i ){
        for( long long x = 1; x <=m ; ++x){
            if( i % 2 == 1 ){
                if( need[i] > x ){
                    best1[x] = best2[x];
                } else {
                    best1[x] = max( (best1[x - need[i] ] + value[i]), best2[x] );
                }    
            }else{
                if( need[i] > x ){
                    best2[x] = best1[x];
                } else {
                    best2[x] = max( (best2[x - need[i] ] + value[i]), best1[x] ); 
                }
            }
        }
    }
    
    if( n % 2 == 1 )
        cout << best1[m] <<endl;
    else
        cout << best2[m] <<endl;

    return 0;
}

