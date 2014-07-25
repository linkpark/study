#!/usr/bin/python
# Filename DataBaseFactory.py

from BaseHandler import*;
from SQLiteHandler import*;
from PGSQLHandler import*;

class DataBaseFactory:
	def __init__(self):
		pass;
	
	def createDataBase(self,baseName):
		if baseName == "SQLite":
			return SQLiteHandler();
		elif baseName == "PGSql":
			return PGSQLHandler();


