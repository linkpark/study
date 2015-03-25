/*
 * =================================================================
 *
 *            Filename:    KnapsackV2.cpp
 *
 *         Description:    这个版本的catch相对要少，交替利用catch，减少存储 
 *                      代价。
 *             Version:    
 *             Created:    2015-03-25 18:55
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

long long best1[100002]= {0};
long long best2[100002]= {0};

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
            if( i % 2 == 0){
                if( need[i] > j ){
                    best1[j] = best2[j];
                }else{
                    best1[j] = max(best2[j], (best2[j-need[i]] + value[i]));
                }
            }else{
                if( need[i] > j ){
                    best2[j] = best1[j];
                }else{
                    best2[j] = max(best1[j], (best1[j-need[i]] + value[i]));
                }
                
            }
        }
    }

    if( n % 2 == 0 ){
        cout << best1[m] << endl;
    }else{
        cout << best2[m] <<endl;
    }
    return 0;
}

