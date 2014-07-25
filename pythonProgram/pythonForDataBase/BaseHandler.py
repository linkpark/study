#!/usr/bin/python
# Filename: BaseHandler.py

def abstract():
	raise NotImplementedError("abstract");

class BaseHandler:
	def __init__(self):
		if self.__class__ is BaseHandler:
			abstract();

