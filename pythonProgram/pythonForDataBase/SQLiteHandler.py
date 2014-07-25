#!/usr/bin/python
# Filename: SQLiteHandler.py

from BaseHandler import*;
import sqlite3;

class SQLiteHandler(BaseHandler):
    def __init__(self):
		BaseHandler.__init__(self);
		print "SQLiteHandler created successful!";
	
    def connectDataBase(self,baseName):
		self.conn = sqlite3.connect(baseName);
		self.cursor = self.conn.cursor();
	
    def excuteQuery(self,query):
		try:
			self.cursor.execute(query);
			self.conn.commit();
		except AttributeError:
			print "you must connect the DataBase first!";
    
    #get Value By the key;
    def getValueByKey(self,key):
        selectQuery = "select * from user where swift_id='%s'" % (key);
        self.cursor.execute(selectQuery);
        result = self.cursor.fetchone();
        value = "";
        for f in result[1:]:
            value = value + f + ":";
        return value;

    #set Value By the key;
    def setValueByKey(self,key,value):
        insertQuery = "insert into user(swift_id,s3_id) values('%s','%s')" % (key,value);
        self.excuteQuery(insertQuery);


