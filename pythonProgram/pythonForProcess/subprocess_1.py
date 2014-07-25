#!/usr/bin/python
# Filename:subprocess_1.py

import subprocess;
pingP = subprocess.Popen(args='ping -c 4 www.sina.com.cn',shell = True);

pingP.wait();
print pingP.pid;
print pingP.returncode


