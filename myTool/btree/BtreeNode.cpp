/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified:	2014-06-17 17:05
#
# Filename:		BtreeNode.cpp
#
# Description: 
#
=============================================================================*/
#include "BtreeNode.h"
#include "Error.h"
#include "Logger.h"
#include <iostream>
#include <exception>
#include <errno.h>
#include <cstring>

BtreeNode::BtreeNode(){
    m_MaxBtreeObject = 0;
    m_Size = 0;
    m_IsDeleted = false;
    m_IsLeafNode = false;
    m_pPairs = NULL;    
    m_pPreNode = NULL;
}

BtreeNode::~BtreeNode(){}

int BtreeNode::init(){
    m_MaxBtreeObject = CONST_NODE_OBJECT_COUNT;
    m_Size = 0;
    try{
        m_pPairs = new struct BtreeKeyValuePair[ CONST_NODE_OBJECT_COUNT ];
    }catch( std::exception error ){
        Logger::writeLogMessage("In BtreeNode::init() new error!",errno);
        return FAILED;
    }
    return SUCCESSFUL;   
}

int BtreeNode::destroy(){
    m_IsDeleted = true;
    
    if( NULL == m_pPairs ){
        std::cout << "m_pPairs has already been deleted!" <<std::endl; 
        return SUCCESSFUL;
    }
    try{
        delete[] m_pPairs;
    }catch( std::exception error ){
        Logger::writeLogMessage("In BtreeNode::destroy() delete error!",errno);
        return FAILED;
    }
    
    m_pPairs = NULL;
    return SUCCESSFUL;
}

int BtreeNode::addPair(int pos,char *key,char *value){
    if(NULL == m_pPairs){
        std::cout << "Init first " <<std::endl;
        return FAILED;
    }
    
    m_pPairs[ pos ].key = key;
    m_pPairs[ pos ].value = value;
    m_Size ++;

    return SUCCESSFUL;
}

int BtreeNode::addPair(const char* key,const char* value){
    if(NULL == m_pPairs){
        std::cout << "Init first" << std::endl;
        return FAILED;
    }
    
    int keyLength = strlen(key) + 1;
    int valueLength = strlen(value) + 1;

    try{
        m_pPairs[m_Size].key = new char[keyLength];
        m_pPairs[m_Size].value = new char[valueLength];
    }catch(std::exception error){
        Logger::writeLogMessage("In BtreeNode::addPair() new error!",errno);
        return FAILED;    
    }
     
    memcpy(m_pPairs[m_Size].key,key,keyLength);
    memcpy(m_pPairs[m_Size].value,value,valueLength);
    m_Size++;

    return SUCCESSFUL;
}

int BtreeNode::removePair(int pos,BtreeKeyValuePair &pair){
    pair.key = m_pPairs[ pos ].key;
    pair.value = m_pPairs[ pos ].value;
    
    m_pPairs[ pos ].key = NULL;
    m_pPairs[ pos ].value = NULL;
    return SUCCESSFUL; 
}

void BtreeNode::setLeaf( bool value ){
    m_IsLeafNode = value;
}

bool BtreeNode::isLeaf(){
    return m_IsLeafNode;
}

bool BtreeNode::isFull(){
    if( CONST_NODE_OBJECT_COUNT == m_Size ){
        return true;
    } 
    return false;
}

BtreeNode* BtreeNode::matchKey( const char* key){
    if(m_IsLeafNode == true)
        return this;

    for(int i = 0 ; i < m_Size ; i++){
        int r = strcmp( key, m_pPairs[i].key );
        if(r <= 0 ){
            return static_cast<BtreeNode*>(m_pPairs[i].value);
        }
    }

    return static_cast<BtreeNode*>(m_pPairs[m_Size].value);
}

/*BtreeNode* BtreeNode::matchKey(const char* key){
    if(m_IsLeafNode == true){
        bool token = false;
        for(int i = 0 ; i < m_Size ; i++){
            if(strcmp( key, m_pPairs[i].key) == 0)
                token = true;
        }
        if( true == token)
            return this;
        else
            return NULL;
    }else{
        for(int i = 0; i < m_Size ; i++){
            int r = strcmp( key, m_pPairs[i].key );
            if(0 == r || -1 == r){
                return (static_cast<BtreeNode*>(m_pPairs[i].value)) \
                    -> matchKey(key);                    
            }
        }

        return (static_cast<BtreeNode*>(m_pPairs[ m_Size ].value))-> \
            matchKey(key);
    }   
}*/

void* BtreeNode::getValueByKey( const char* key ){
    if(m_IsLeafNode == false)
        return NULL;
    
    for( int i = 0 ; i < m_Size ; i ++){
        if(strcmp( key , m_pPairs[i].key) == 0)
            return m_pPairs[i].value;
    }

    return NULL;
}

