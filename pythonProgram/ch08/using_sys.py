# !/usr/bin/python
# Filename:using_sys.py

import sys

print 'The commond line arguments are:';
for i in sys.argv:
	print i;

print '\n\nThe PYTHONPATH is ',sys.path,'\n';

