#!/usr/bin/python
# Filename: thread_2.py

import threading;
import time;

class ThreadDemo(threading.Thread):
	def __init__(self,index,create_time):
		threading.Thread.__init__(self);
		self.index = index;
		self.create_time = create_time;
	
	def run(self):
		time.sleep(1);
		print(time.time() - self.create_time),"\t",self.index;
		print "Thread %d exit..." % (self.index);

#threads = [];
for index in range(5):
	thread = ThreadDemo(index,time.time());
	thread.start();
#	threads.append(thread);

#for thread in threads:
#	thread.join();
time.sleep(10)	 
print "Main thread exit ...";


