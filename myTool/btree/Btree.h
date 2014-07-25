#ifndef BTREE_H_
#define BTREE_H_
#include "BtreeNode.h"
class Btree{
public:
    Btree();
    virtual ~Btree();

private:
    Btree(const Btree&);
    const Btree& operator=(const Btree&);

public:
    int initBtree(const char* filename);
    //int destroyBtree();
    
    int addPair(const char *key,const char *value);
    BtreeNode* findNode(const char *key)const;
    BtreeNode* findPreNode(BtreeNode *btreeNode)const;

    //int deletePair(char *key);
    //int readPair(char *key,char *value);

private:
    BtreeNode *root;
};
#endif
