/*
 * =================================================================
 *
 *            Filename:    TenForkTree.cpp
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-10-06 16:28
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
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

