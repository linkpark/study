#include <iostream>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <cstring>
#include <cstdio>
#include <error.h>

const int FAILED = -1;
const int SUCCESSFUL = 0;

using namespace std;

int setFileOffset(int fd, off_t offset){
    if( lseek(fd,offset,SEEK_SET) < 0){
        perror("lseek error!");
        return FAILED;
    }

    return SUCCESSFUL;
}

int main(int argc,char **argv){
    if( 2 != argc ){
        cout << "Usage:<main> <file name> " <<endl;
        return FAILED;
    }

    int n;
    int fileFd = open(argv[1],O_APPEND|O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH );
    char buf[100];
    const char* addContent = "this is an add content!\n";

    if( (n = write(fileFd,addContent,strlen(addContent))) < 0 ){
        perror("write error!\n");
        return FAILED;
    } 

    if( (n = read(fileFd,buf,100)) == 0){
        cout << "reach the end of file" <<endl;
    }else if(n > 0){
        cout << buf <<endl;
    }else{
        cout << "read error!" <<endl;
        return FAILED;
    }
    
    memset(buf,0,100);

    setFileOffset(fileFd,0);

    if( (n = read(fileFd,buf,100)) == 0){
        cout << "reach the end of file" <<endl;
    }else if(n > 0){
        cout << buf <<endl;
    }else{
        cout << "read error!" <<endl;
        return FAILED;
    }
    
    return SUCCESSFUL;    
}

