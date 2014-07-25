#/usr/bin/python
# Filename: MemchedHandler.py

import memcache

class MemchedHandler:
	def __init__(self,ip,port):
		connectPro = ip + ":" + port;
		print connectPro;
		self.memcacheObj = memcache.Client([connectPro],debug=0);
	def setValue(self,key,value):
		self.memcacheObj.set(key,value);

	def getValue(self,key):
		return self.memcacheObj.get(key);

