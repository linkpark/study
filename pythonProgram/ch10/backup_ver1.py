# !/usr/bin/python
# Filename: backup_ver1.ply

import os;
import time;

source = ['/home/wj/wj/pythonProgram/ch06'];

target_dir = '/root/wangjin/backup/';

target = target_dir + time.strftime('%Y%m%d%H%M%S') + '.tar.gz';
print target;

tar_command = "tar zcfP %s %s" % (target,' '.join(source));

print tar_command;

if os.system(tar_command) == 0:
	print 'Successful backup to',target;
else:
	print 'Backup FAILED';


