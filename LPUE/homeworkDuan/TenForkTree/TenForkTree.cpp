#include <iostream>
#include <fstream>
#include <string>
#include "TenForkTree.h"

using namespace std;

template<class T>
TenForkTree<T>::TenForkTree():m_pRoot(nullptr),m_pCurrentPosition(nullptr){
       
}

template<class T>
TenForkTree<T>::~TenForkTree(){
}

template<class T>
int TenForkTree<T>::deserialize(const char* filePath){
    ifstream inputFile(filePath,ios::in);
    T value;
    int number;
    
    while(inputFile >> value){
        inputFile >> number;
        for(int i = 0 ; i < number ; ++i){
            
        } 
    }
}
