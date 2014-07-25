#!/usr/bin/python
# Filename:urllib_1.py

import urllib;
fp = urllib.urlopen("http://222.197.182.156/index.jsp");

op = open("index.html","wb");

n = 0
while True:
	s = fp.read(1024);
	if not s:
		break;
	op.write(s);
	n = n + len(s);

fp.close();
op.close();

print "retrieved",n," bytes from",fp. url;


