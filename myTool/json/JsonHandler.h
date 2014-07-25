/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-07 16:17
#
# Filename: JsonHandler.h
#
# Description: this can't support json array 
#
=============================================================================*/
#ifndef JSONHANDLER_H_
#define JSONHANDLER_H_
#include <json/json.h>
#include <string>

class JsonHandler{
private:
    Json::Reader m_Reader;
    Json::Value m_Value;
    Json::Writer m_Writer;

public:
    JsonHandler(){}
    ~JsonHandler(){}

public:
    int loadJsonStr(char *pStr);
    std::string getValueByKey(const char* cpStr);
    std::string setJsonObj(Json::Value value);
};

#endif
