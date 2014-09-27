#ifndef FILEOPERATOR_H_
#define FILEOPERATOR_H_

const int DEFAULTBUFSIZE = 1024;

class FileOperator{
public:
    FileOperator(int bufSize);
    FileOperator();

     ~FileOperator();

public:
    int fileOpen();
    int fileRead();
    int fileWrite();
    int fileLseek();
    int fileClose();
    
private:
    int m_iFileFd;
    int m_iBufSize;
    char *m_pBuf;
};

#endif
