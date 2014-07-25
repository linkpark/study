/*=============================================================================
#
# Author: wj 
#
# mail : wjlinkpark@gmail.com
#
# Last modified: 2014-06-04 14:43
#
# Filename: CriticalSection.h
#
# Description: 
#
=============================================================================*/
#ifndef CRITICALSECTION_H_
#define CRITICALSECTION_H_
#include "Mutex.h"

class CriticalSection{
public:
    CriticalSection(Mutex *pMutex);
    virtual ~CriticalSection();

private:
    CriticalSection(const CriticalSection &criticalSection);
    CriticalSection& operator=(const CriticalSection &criticalSection);    

private:
    Mutex *m_pMutex;
};

#endif
