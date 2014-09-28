#ifndef FILEOPERATOR_H_
#define FILEOPERATOR_H_
#include <sys/types.h>

const int DEFAULTBUFSIZE = 1024;

class FileOperator{
public:
    FileOperator();
     ~FileOperator();

public:
    int initial(int bufSize);
    void destory();

    int fileOpen(const char* path,int flags,mode_t mode);
    int fileRead();
    int fileWrite();
    int fileLseek();
    int fileClose();

private:
    int flush();

private:
    int m_iFileFd;
    int m_iBufSize;
    int m_iUsedBufSize;
    int m_iFileOffset;

    char *m_pWriteBuf;
    char *m_pReadBuf;
};

#endif
