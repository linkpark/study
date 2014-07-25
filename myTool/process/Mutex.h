/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-05-30 16:15
#
# Filename: Mutex.h
#
# Description: 
#
=============================================================================*/
#ifndef MUTEX_H_
#define MUTEX_H_
#include <pthread.h>
class Mutex{
public:
    Mutex();
    virtual ~Mutex();

    int initLock();
    int destoryLock();

    int lock();
    int unLock();
    pthread_mutex_t getMutex()const;

private:
    Mutex(const Mutex&);
    Mutex& operator=(const Mutex&);

private:
    pthread_mutex_t m_Mutex;
};
#endif
