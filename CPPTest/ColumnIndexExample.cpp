#include <iostream>
#include <map>
#include <utility>
#include <set>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

map< string,int > dic;

vector< int > 
generateAttributeVector(const char *path,int length){
    ifstream inputFile(path);
    vector< int > attributeVector(length);
    string word;
    int i = 0;

    while(!inputFile.eof()){
        inputFile >> word;
        attributeVector[ i ] = dic[ word ];
    }

    return attributeVector;   
}

int generateDic(const char* path){
    ifstream inputFile(path);
    string word;
    int count = 0;
    set< string > order;
    
    while(!inputFile.eof()){
        inputFile >> word;
        order.insert(word); 
        count ++;
    }

    int i = 0;
    
    for(set< string >::iterator ix = order.begin(); ix != order.end(); ix++){
        dic[*ix] = i;
        i++;
    }
    
    return count;    
}

void printDic(){
    for(map<string,int>::iterator ix = dic.begin(); ix != dic.end();ix++){
        cout << ix->first <<" " << ix->second <<endl;
    }
}

int main(int argc,char **argv){
    if(2 != argc){
        cout << "input error!" <<endl;
        return 1;
    }
    generateDic( argv[1]);
    printDic();
    
    return 0;
}

