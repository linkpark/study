#include <iostream>
#include <stdio.h>

using namespace std;

int best[102][102];

int max( int a , int b ){
    return a > b ? a : b;
}

int main(){
    int rewords[102][102];
    int n;
    int ans = 0;

    scanf("%d", &n);
    scanf("%d", &rewords[1][1]);

    if( n == 1 ){
        ans = rewords[1][1];
    }

    best[1][1] = rewords[1][1];

    for( int i = 2; i <= n ; i++){
        for( int j = 1; j <= i ; ++j ){
            scanf("%d",&rewords[i][j]);
            best[i][j] = max(best[i-1][j],best[i-1][j-1]) + rewords[i][j]; 
            if( ans < best[i][j])
                ans = best[i][j];
        }
    }

    printf("%d\n",ans);

    return 0;
}
