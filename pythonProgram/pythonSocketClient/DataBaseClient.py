#/usr/bin/python
# Filename DataBaseClient.py

import socket;
import json;

class DataBaseClient:
    def __init__(self,ip,port):
        self.socketFd = socket.socket(socket.AF_INET,socket.SOCK_STREAM);
        self.socketFd.connect((ip,port));
    
    def getValueByKey(self,key):
        protocol = '{"method":"get","key":"%s","value":" "}\n' % (key);
        self.socketFd.send(protocol);
        response = self.socketFd.recv(1024);
        result = json.loads(response);

        if result["state"] == "ok":
            return str(result["value"]);
        else:
            print "error";
            return None;
    
    def setValueBykey(self,key,value):
        protocol = '{"method":"set","key":"%s","value":"%s"}\n' % (key,value);
        self.socketFd.send(protocol);
        response = self.socketFd.recv(1024);
        result = json.loads(response);

        if result["state"] == "ok":
            return True;
        else:
            return False;

if __name__ == "__main__":
    dataBaseClient = DataBaseClient("localhost",6000);
    print dataBaseClient.getValueByKey("4");


