#ifndef TASK_H_
#define TASK_H_

class Task{
public:
    virtual int readTask(void *pContext) = 0;
    virtual int writeTask(void *pContext) = 0;
};

#endif
