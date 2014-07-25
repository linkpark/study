/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-06-17 17:05
#
# Filename: BtreeDefine.h
#
# Description: 
#
=============================================================================*/
#ifndef BTREEDEFINE_H_
#define BTREEDEFINE_H_
#include <cstring>

struct BtreeKeyValuePair{
    char* key;
    void* value;
};


const int CONST_MAX_DEPTH = 3;
const int CONST_NODE_OBJECT_COUNT = 10;
const int CONST_KEY_MAX_LENGTH = 1024;
const int CONST_BIG = 1;
const int CONST_LESS = -1;
const int CONST_EQUAL = 0;

#endif 
