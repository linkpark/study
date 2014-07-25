#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int WORD_LENGTH = 1200002;
char word[WORD_LENGTH];

int judge(char *p){
    int maxSubStringLen = 1;
    for(int i = 1; p[i] != '\0';i++){
        int centerRight = i; 
        int centerLeft = i; 

        while(p[centerRight+1] == p[i])++centerRight;

        i = centerRight;

        while(p[centerLeft-1] == p[centerRight+1]){
            centerLeft--;
            centerRight++;
        }

        if( centerRight - centerLeft + 1 > maxSubStringLen )
            maxSubStringLen = centerRight - centerLeft + 1;
    }    

    return maxSubStringLen;
}

int main(){
    word[0] = '$';
    int m;
    scanf("%d",&m);
    while(m > 0){
        scanf("%s",word+1);
        printf("%d\n",judge(word));
        m--;
    }
    return 0;
}
