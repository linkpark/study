#! /usr/bin/env python
# Filename:Listener.py


import eventlet;
import json;
from MemcachedHandler import*;
from DataBaseFactory import*;


memcacheHandler = MemchedHandler("192.168.1.74","12000");
dataBaseFactory = DataBaseFactory();
dataBaseHandler = dataBaseFactory.createDataBase("SQLite");
dataBaseHandler.connectDataBase("mydatabase");

#the function is used to handle set method;
def setMethodHandler(socketFd,key,value):
    try:
        dataBaseHandler.setValueByKey(key,value);
        memcacheHandler.setValue(key,value);
        rightMessage = '{"state":"ok","data":" "}\n';
        socketFd.write(rightMessage);
    except Exception:
        errorMessage = '{"state":"error","data":"can not insert"}\n';
        socketFd.write(errorMessage);

#the function is used to handle get method;
def getMethodHandler(socketFd,key):
   value = memcacheHandler.getValue(key);
   if value == None:
       print "data come from sqlite";
       value = dataBaseHandler.getValueByKey(key);
       memcacheHandler.setValue(key,value);
   else:
       print "data come from memcache";

   response = '{"state":"ok","value":"%s"}\n' % (value);
   socketFd.write(response);

#handle function
def handle(fd):
    print "client connected"
    while True:
        # pass through every non-eof line
        x = fd.readline();
        if not x: break;
        
        s = json.loads(x);
        print x;

        if s["method"] == "get":
            getMethodHandler(fd,str(s["key"]));

        if s["method"] == "set":
            setMethodHandler(fd,str(s["key"]),str(s["value"]));

        fd.flush()
        print "echoed", x,
    print "client disconnected"

print "server socket listening on port 6000"
server = eventlet.listen(('0.0.0.0', 6000))
pool = eventlet.GreenPool()
while True:
    try:
        new_sock, address = server.accept()
        print "accepted", address
        pool.spawn_n(handle, new_sock.makefile('rw'))
    except (SystemExit, KeyboardInterrupt):
        break;

