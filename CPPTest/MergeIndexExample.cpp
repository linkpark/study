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
generateDic(const char* path, vector<string> &oldDic){
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
        oldDic.push_back( *ix );
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

void printDic(){
    cout << "dictionary table" <<endl;
    for(map<string,int>::iterator ix = dic.begin(); ix != dic.end();ix++){
        cout << ix->first <<" " << ix->second <<endl;
    }
}

vector< string > generateDeltaData(const char *path){
    ifstream inputFile(path);
    string word;
    vector<string> DeltaData;
    while(inputFile >> word){
        DeltaData.push_back(word);
    }   

    return DeltaData;
}

void merge(
        vector< int > &oldPositionIndex,
        vector< int > &oldOffsetIndex,
        vector< string > &oldDic,
        vector< string > &deltaData, 
        vector< int > &newPositionIndex,
        vector< int > &newOffsetIndex,
        vector< string > &newDic
        ){

    vector< int > increaseVector(oldDic.size(),0);
    map< string,int > wordCount;
    unsigned long d(0),m(0),n(0),c(0);
    int count;

    for(unsigned long i = 0; i < deltaData.size(); i ++){
        if(wordCount.count( deltaData[i] ) == 0){
            wordCount[ deltaData[i] ] = 0;
        }

        wordCount[ deltaData[i] ]++;
    }
    
    newPositionIndex.resize( oldPositionIndex.size() + deltaData.size() );
    bool processA = true;
    bool processB = true;

    while( d != deltaData.size() || m != oldDic.size() ){
        count = 0;
        newOffsetIndex.push_back(c);
        
        processA = false;
        processB = false;

        if(  d == deltaData.size() )
            processA = true;
        else if(oldDic[m] <= deltaData[d] )
            processA = true;
        
        if( oldDic[m] >= deltaData[d] || m == oldDic.size() )
            processB = true;
        else
            processB = false;

        if(processA){
            newDic.push_back( oldDic[m] );

            increaseVector[m] = n - m;
             
            count = oldOffsetIndex[m+1] - oldOffsetIndex[m]; 
            
            for(int i = oldOffsetIndex[m] ; i <oldOffsetIndex[m+1] ; i++){
                 newPositionIndex[c] = oldPositionIndex[i];
                 c++;
            }

            m++;
        }

        if(processB){
            if(processA != processB)
                newDic.push_back(deltaData[d]);

             count = wordCount[ deltaData[d] ];

             for(int i = 0 ; i < count  ;i ++)
                 newPositionIndex[c + i] = oldPositionIndex.size() + i + 1;
            
             c += count;
             d += count;
        }
        
        n++;
    } 
}

template <class T>
void 
printVector(T& vector){
    int i = 0;
    for(typename T::iterator ix = vector.begin() ; ix != vector.end(); ix++){
        cout <<i << " " <<*ix << endl;
        i++;
    } 
}

int 
main(int argc,char **argv){
    if(3 != argc){
        cout << "input error!" <<endl;
        return 1;
    }

    vector< int > attributeVector;
    vector< int > indexVector;
    vector< int > positionVector;
    vector< string > oldDic; 
    vector< string > deltaData;
    vector< int > newIndexVector;
    vector< int > newPositionVector;
    vector< string > newDic; 
    int n;

    n = generateDic( argv[1],oldDic );
    printVector(oldDic);
    attributeVector = generateAttributeVector( argv[1],n );
    indexVector = generateIndexVector( attributeVector );
    positionVector = generatePositionVector( attributeVector,indexVector );
    deltaData = generateDeltaData( argv[2] );
    
    cout << "old attribute vector table" <<endl;
    printVector(attributeVector);

    cout << "old index vector table "<<endl;
    printVector(indexVector);
    
    cout << "old position Vector" <<endl;
    printVector(positionVector);
    printVector(deltaData);
    merge(positionVector, indexVector,oldDic,deltaData,newPositionVector,newIndexVector,newDic);
    return 0;
}

