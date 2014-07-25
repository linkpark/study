#include <iostream>
#include <fstream>
#include <error.h>
#include "Btree.h"
#include "Logger.h"
#include "Error.h"

using namespace std;

Btree::Btree():root(NULL){
}

Btree::~Btree(){
}

int Btree::initBtree(const char* filename){
    fstream file;
    file.open(filename);
    string key;
    string value;
     
    while(  !file.eof() ){
        file >> key >> value;
        addPair( key.c_str(),value.c_str() );
    }

    return SUCCESSFUL;  
}

int Btree::addPair(const char *key, const char *value){
    if( NULL == root){
        root = new BtreeNode();
        root->addPair( key , value );
        root->setLeaf(true);
    }   
    
    BtreeNode *p = findNode( key );
    if(!p->isFull()){
        p->addPair( key , value );
    }else{
        /*b+树的分裂策略*/ 
    }

    return SUCCESSFUL;
}

BtreeNode* Btree::findNode( const char* key)const{
    BtreeNode *p = root;
    while( !p->isLeaf() ){
        p = p -> matchKey(key);           
    }

    return p;
}


