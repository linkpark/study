/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-06-17 17:05
#
# Filename: BtreeNode.h
#
# Description: 
#
=============================================================================*/
#ifndef BTREENODE_H_
#define BTREENODE_H_
#include "BtreeDefine.h"
class BtreeNode{
public:
    BtreeNode();
    virtual ~BtreeNode();

private:
    BtreeNode(const BtreeNode&);
    const BtreeNode& operator=(const BtreeNode&);

public:
    int init();
    int destroy();
    
    int addPair(int pos, char *key,char* value);
    int addPair(const char *key, const char* value);
    int removePair(int pos,BtreeKeyValuePair &pair);
    BtreeNode* matchKey(const char* key);
    void* getValueByKey(const char* key);

    void setLeaf(bool value);
    bool isLeaf();

    bool isFull();

private:
    int m_MaxBtreeObject;
    int m_Size;
    bool m_IsDeleted;
    bool m_IsLeafNode;
    struct BtreeKeyValuePair *m_pPairs; 

    //记录父节点的指针信息
    BtreeNode* m_pPreNode;
};

#endif 

