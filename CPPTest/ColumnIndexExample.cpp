#include <iostream>
#include <map>
#include <utility>
#include <set>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

//全局字典
map< string,int > dic;

vector< int > 
generateAttributeVector(const char *path,int length){
    ifstream inputFile(path);
    vector< int > attributeVector(length);
    string word;
    int i = 0;
    while(inputFile >> word){
        attributeVector[ i ] = dic[ word ];
        i++;
    }

    return attributeVector;   
}

int 
generateDic(const char* path){
    ifstream inputFile(path);
    string word;
    int count = 0;
    set< string > order;
    
    while(inputFile >> word){
        order.insert(word); 
        count++;
    }

    int i = 0;
    
    for(set< string >::iterator ix = order.begin(); ix != order.end(); ix++){
        dic[*ix] = i;
        i++;
    }
    
    return count;    
}

vector< int >
generateIndexVector(vector<int> &attributeVector){
    vector<int> indexVector(dic.size()); 
    int *valueCount = new int(dic.size());

    memset(valueCount,0,dic.size() * sizeof(int));

    for(vector<int>::iterator ix = attributeVector.begin(); 
            ix !=attributeVector.end();ix++ ){
        valueCount[*ix]++;  
    }

    indexVector[0] = 0;

    for(unsigned long i = 0; i < dic.size() -1 ;i++){
        indexVector[i+1] = indexVector[i] + valueCount[i];
    }

    return indexVector;
}

vector<int> 
generatePositionVector(vector<int> &attributeVector,
        vector<int> &indexVector){
    vector<int> positionVector(attributeVector.size(),-1);
    int i =0;

    for(vector<int>::iterator ix = attributeVector.begin();
            ix != attributeVector.end();ix++){
        int offset = indexVector[*ix];
        while(positionVector[offset] != -1){
            offset++;
        }
        positionVector[offset] = i;
        i++;
    }          

    return positionVector;
}

void 
printDic(){
    cout << "dictionary table" <<endl;
    for(map<string,int>::iterator ix = dic.begin(); ix != dic.end();ix++){
        cout << ix->first <<" " << ix->second <<endl;
    }
}

int 
main(int argc,char **argv){
    if(2 != argc){
        cout << "input error!" <<endl;
        return 1;
    }

    vector< int > attributeVector;
    vector< int > indexVector;
    vector< int > positionVector;
    int n;

    n = generateDic( argv[1]);
    printDic();
    attributeVector = generateAttributeVector(argv[1],n);
    indexVector = generateIndexVector(attributeVector);
    positionVector = generatePositionVector(attributeVector,indexVector);
    
    cout << "attribute vector table" <<endl;
    for(unsigned long i = 0; i < attributeVector.size(); i++){
        cout <<i << " " << attributeVector[i] <<endl;
    }

    cout <<endl;
    
    cout << "index vector table "<<endl;
    for(unsigned long i = 0; i < indexVector.size(); i++){
        cout << i << " " << indexVector[i] <<endl;
    }
    
    cout <<endl;

    cout << "position Vector" <<endl;
    for(unsigned long i = 0; i < positionVector.size(); i++){
        cout << i << " " << positionVector[i] <<endl;    
    }

    cout << endl;

    return 0;
}

