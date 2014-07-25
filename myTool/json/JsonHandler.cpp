#include "../log/Error.h"
#include "../log/Logger.h"
#include "JsonHandler.h"

#include <stdio.h>
#include <string>

int JsonHandler::loadJsonStr(char *pStr){
    if(!m_Reader.parse(pStr,m_Value)){
        Logger::writeLogMessage("JsonHandler::loadJsonStr error!",errno);
        return FAILED;
    }

    return SUCCESSFUL;
}

std::string JsonHandler::getValueByKey(const char* cpStr){
    return m_Value[cpStr].asString();
}

