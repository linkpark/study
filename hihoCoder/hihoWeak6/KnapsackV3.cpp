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

long long best[100002]= {0};

int main(){
    long long n,m;
    long long value[ 502 ];
    long long need [ 502 ];

    scanf( "%lld %lld", &n, &m );

    for( long long i = 1 ; i <= n ; ++i ){
        scanf( "%lld %lld", &need[i], &value[i] );
    }
    
    for( long long i = 1; i <= n ; ++i ){
        for( long long j = m ; j >= need[i] ; --j ){
            best[j] = max( best[j], best[j - need[i]]+value[i]); 
        }
    }

    cout << best[m] <<endl;

    return 0;
}

