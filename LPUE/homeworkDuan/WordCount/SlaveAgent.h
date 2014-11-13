#ifndef SLAVEAGENT_H_
#define SLAVEAGENT_H_
#include "comm/Agent.h"
#include "comm/TCPSocket.h"
#include <string>
#include <map>

struct WordPair{
    int count;
    char word[256];
};

class SlaveAgent:public Agent{
public:
    SlaveAgent(TCPSocket &clientSocket, std::string &fileName, std::map< std::string , int > *pMap, int *pJobCount);
    ~SlaveAgent();

    int readData( void );
    int writeData( void );

private:
    void printWordMap();

private:
    TCPSocket m_TcpSocket; 
    
    std::string m_FileName;
    std::map< std::string, int > *m_pWordCountBuffer;
    int *m_pJobCount;
};
#endif
