#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;

int createRand(int begin,int end){
    return rand()%( end - begin ) + begin;
}

string createRandWord(int seed){
    srand( seed );
    int length =  createRand(1,20);
    char temp[21];
    memset(temp,0,21);
    for(int i = 0 ; i< length ; i ++ ){
        temp[i] = 'a' + createRand(0,21);
    }

    string word(temp);
    return word;
}

int main(int argc,char **argv){
    if(3 != argc ){
        cout << "Usage: <createWord> <filename> <wordNumber> !" <<endl;
        return 0;
    }
    
    int count = 0;
    ofstream file;
    string word;

    file.open(argv[1]);

    for(int i = 0 ; i < atoi( argv[2] ) ; i ++ ){
        count ++;
        word = createRandWord(i);
        file << word << endl;
        if(count == 20 ){
            file << "\n";
            count = 0;
        }
    }

    return 0;
}

