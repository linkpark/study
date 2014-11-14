/*
 * =================================================================
 *
 *            Filename:    Channel.h
 *
 *         Description:    
 *
 *             Version:    v1.0
 *             Created:    2014-11-14 16:34
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#ifndef CHANNEL_H_
#define CHANNEL_H_

class Channel{
public:
    Channel():m_WriteFd(-1),m_ReadFd(-1){}
    virtual ~Channel(){}

    virtual int getWriteFd() = 0;
    virtual int getReadFd() = 0;
    virtual int initial() = 0;

protected:
    int m_WriteFd;
    int m_ReadFd;
};
#endif
