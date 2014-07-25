#!/usr/bin/python
# Filename thread_1.py

import thread;
import time;

def worker(index,create_time):
	time.sleep(0.5);
	print (time.time() - create_time),"\t\t",index;
	print "Thread %d exit.." % (index);

for index in range(5):
	thread.start_new_thread(worker,(index,time.time()));

time.sleep(10);
print "Main thread exit...";


