#!/usr/bin/python
# Filename:tcpClient.py

import socket

def tcpClient():
    cliSocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM);
    cliSocket.connect(('localhost',6000));

    cliSocket.send('{"method":"get","key":"12","value":"212"}\n');
    data = cliSocket.recv(1024);
    print data;

if __name__ == "__main__":
    tcpClient();

