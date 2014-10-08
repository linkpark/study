/* 
 * =================================================================
 *
 *            Filename:    TenForkTree.h
 *
 *         Description:    ten fork tree seriliazed and deseriliazed 
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
#ifndef TENFORKTREE_H_
#define TENFORKTREE_H_
#define TREEFORKNUMBER 10
#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int SUCCESSFUL = 0;
const int FAILED = -1;

template<class T>
struct node{
    T value;
    int childNumber;
    struct node *next[TREEFORKNUMBER];
}; 

template<class T>
class TenForkTree{
public:
    TenForkTree():m_pRoot(nullptr),m_pCurrentPosition(nullptr){
        srand( (unsigned)time(NULL) ); 
    }

    ~TenForkTree(){
    }

public:
    int serialize(const char * filePath){
        ofstream outputFile( filePath, ios::out );
        if(nullptr == m_pRoot){
            cout << "empty tree " <<endl;
            return FAILED;
        }
    
        serializeNode( m_pRoot, outputFile);
        return SUCCESSFUL;
    }

    int deserialize(const char *filePath){
        ifstream inputFile(filePath,ios::in);

        deserializeNode( &m_pRoot , inputFile );

        return SUCCESSFUL;
    }
    
    void destoryTheTree(){
        if( nullptr != m_pRoot ){
            freeTreeNode( m_pRoot );
        }
    }
    
    void preorderTraversal(){
        preorder(m_pRoot);
    }

    void constructRandomTree(int treeDepth);

private:    
    /*node节点的特化*/
    void constructRandomTreeNode(struct node<T> **nodePtr,int treeDepth);

    /*****************************************
    *  Function name: deserializeNode
    *    Description: 反序列化节点，由于需要改变指针本身的值
    *           所以这里必须用双重指针来构建树
    *         Return: void
    *
     *****************************************/
    void deserializeNode( struct node<T> **nodePtr, ifstream& inputFile){
        T value;
        int number;

        inputFile >> value;
        inputFile >> number;

        (*nodePtr) = new struct node<T>(); 
        (*nodePtr)->value = value;
        (*nodePtr)->childNumber = number;

        for( int i = 0; i < number ; ++i){
            deserializeNode( &( (*nodePtr)-> next[i]) , inputFile);
        }
    }

    void serializeNode( struct node<T> *nodePtr, ofstream& outputFile){
        if(nodePtr == nullptr) 
            return;

        outputFile << nodePtr -> value << " " << nodePtr ->childNumber << endl;

        for( int i = 0; i < nodePtr -> childNumber ; i++){
            serializeNode( nodePtr -> next[i] , outputFile);
        } 
    }

    void freeTreeNode(struct node<T> *nodePtr){
        if( nodePtr->childNumber != 0)
            for(int i = 0 ;i < nodePtr -> childNumber ; ++i)
                freeTreeNode(nodePtr->next[i]);

        delete nodePtr;
        nodePtr = nullptr;
    }

    void preorder(struct node<T> *nodePtr){
        cout << nodePtr->value << " ";
        for(int i = 0; i < nodePtr->childNumber ; i++){
            preorder( nodePtr->next[i] );
        }
    }

    inline int createRandomNumber(int begin,int end){
        return (( rand() % (end - begin + 1) ) + begin);
    }

private:
    struct node<T> *m_pRoot;
    struct node<T> *m_pCurrentPosition;
};

/*特化树的构造树的函数*/
template<>
void TenForkTree<string>::constructRandomTreeNode(node<string> **nodePtr, int treeDepth){
    string value( 1,'a' + createRandomNumber(0,26) );
    
    (*nodePtr) = new struct node<string>();
    (*nodePtr)->value = value;

    if(treeDepth != 0){
        (*nodePtr)->childNumber = createRandomNumber( 1,10 );
        for(int i = 0 ; i < (*nodePtr)->childNumber ; ++i )
            constructRandomTreeNode( &((*nodePtr)->next[i]) , treeDepth - 1 );
    }else{
        (*nodePtr)->childNumber = 0;
    }
}

template<>
void TenForkTree<string>::constructRandomTree(int treeDepth){
    constructRandomTreeNode( &m_pRoot, treeDepth-1 );
}

#endif
