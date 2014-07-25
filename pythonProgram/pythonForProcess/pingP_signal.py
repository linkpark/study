#!/usr/bin/python
# Filename: pingP_signal.py

import subprocess;
import signal;

def sigintHandler(signum,frame):
	print "In signal SIGINT handler";

signal.signal(signal.SIGINT,sigintHandler);

pingP = subprocess.Popen(args = 'ping -c 4 www.sina.com.cn',shell=True);

pingP.wait();
print pingP.pid;
print pingP.returncode;

