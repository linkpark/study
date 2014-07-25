# !/usr/bin/python
# Filename:ccseBackup.py
# before using this script,you should add the files into svn
import os;
import time;


source = ['/usr/local/tomcat7/webapps/ROOT/upload'];
targetDir = '/root/backupFromCenter/'

#create logfile
logFileName = targetDir + 'ccsebackup.log';
print logFileName;
logFile = file(logFileName,'a+');

today = time.strftime('%Y-%m-%d %H:%M:%S:');

#backup upload file
target = targetDir + "upload.tar.gz"
tarCommand = "tar zcfP %s %s" % (target,' '.join(source));
logFile.write(today+'\n');

#backup mysql
sourceDataBase = 'ccse';
mysqlHost = '127.0.0.1';
mysqlUser = 'root';
mysqlPasswd = 'uestc8020';
mysqlTarget = targetDir + 'ccsebackup.sql';

mysqlCommand = "mysqldump -h%s -u%s -p%s %s > %s" % (mysqlHost,mysqlUser,mysqlPasswd,sourceDataBase,mysqlTarget);

if os.system(tarCommand) == 0:
	logFile.write("    ccse upload file back up successsful!\n");	
else:
	logFile.write("    ccse upload file back up failed!\n");

if os.system(mysqlCommand) == 0:
	logFile.write("    mysql back up successful!\n");
else:
	logFile.write("    mysql back up failed!\n");

#svn operation
os.system("source /etc/profile");

svnCommand = "svn ci -m '%s' %s" % (today,targetDir);
print svnCommand;

a = os.system(svnCommand);

if a == 0:
	logFile.write("    svn submit successful!\n");
else:
	logFile.write("   svn resubmit error! errorCode:%s\n" % (a));


