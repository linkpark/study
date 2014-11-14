/*
 * =================================================================
 *
 *            Filename:    FIFOChannel.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-14 16:41
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef FIFOCHANNEL_H_
#define FIFOCHANNEL_H_
#include <string>
#include "Channel.h"

class FIFOChannel:public Channel{
public:
    FIFOChannel(const char* fifoName);
    ~FIFOChannel();
    
public:
    int getWriteFd( void );
    int getReadFd( void );
    int initial( void );

private:
    std::string m_FIFOName;

    bool m_bIsInitial;
};

#endif
