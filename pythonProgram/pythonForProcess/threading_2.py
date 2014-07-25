#!/usr/bin/python
# Filename: threading_2.py

import threading;
import time;

class Counter:
	def __init__(self):
		self.value = 0;
	def increment(self):
		self.value = self.value + 1;
		value = self.value;
		return value;
	
counter = Counter();

class ThreadDemo(threading.Thread):
	def __init__(self,index,createTime):
		threading.Thread.__init__(self);
		self.index = index;
		self.createTime = createTime;

	def run(self):
		time.sleep(1);
		value = counter.increment();
		print (time.time() - self.createTime),"\t",self.index,"\tvalue:",value;
	

for index in range(400):
	thread = ThreadDemo(index,time.time());
	thread.start();





