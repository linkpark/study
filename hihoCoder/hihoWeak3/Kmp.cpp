#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*int* generateNextArray(char *pStr){
    int arrayLength = strlen(pStr);
    int *nextArray = new int[arrayLength];
    bool token = false;
    nextArray[0] = -1;
    
    for(int i = 0 ; i < arrayLength - 1 ; i++){
        int k = 0;
        for(int m = 0; m < i; m ++){
            for(int j = 0 ; j <= m; j ++){
                if( pStr[j] != pStr[i - m + j] ){
                    token = true;
                    break;
                }
            }
            if( token == false ){
                if( m + 1 > k)
                    k = m + 1;
            }

            token = false;
        }
        nextArray[i + 1] = k;    
    }

    return nextArray;
}*/

int* generateNextArray(char *pStr){
    int i = 1;
    int j = 0;
    int *next = new int[strlen(pStr) + 1];
    next[0] = -1;
    next[1] = 0;
    while( i < (int)strlen(pStr)){
        if( j == 0 || pStr[i] == pStr[j]){
            i++;
            j++;
            next[i] = j;
        }else
            j = next[j];
    }

    return next;
}

void deleteNextArray(int* &array){
    if(array == NULL)
        return;
    
    delete[] array;
    array = NULL;
}

int Kmp(char *pSource,char *pTarget){
    int *nextArray = generateNextArray(pSource); 
    int i = 0;
    int j = 0;
    int count = 0;
    int begin = i;
    while(pTarget[begin] != '\0'){
        if(pSource[j] == pTarget[i]){
            i++;
            j++;
            if( pSource[j] == '\0'){
                count ++;
                begin ++;
                j = 0;
                i = begin;
            }
            continue;
        }else{
            begin += j - nextArray[j];
            j = 0;
            i = begin;
        } 
    } 

    deleteNextArray(nextArray); 
    return count;
}


int main(){
    char source[10004];
    char target[1000004];
    int m;
    scanf("%d",&m);
    while(m--){
        scanf("%s",source);
        scanf("%s",target);
        cout << Kmp(source,target) <<endl;
    }
    return 0;
}

