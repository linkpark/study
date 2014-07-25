# !/usr/bin/python
# Filename:backup_ver2.py

import os;
import time;

source = ['/root/wangjin/pythonProgram/ch06'];

target_dir = '/root/wangjin/backup/'

today = target_dir + time.strftime('%Y%m%d');
now = time.strftime('%H%M%S');

if not os.path.exists(today):
	os.mkdir(today);
	print 'Successfully created directory',today;

target = today + os.sep + now + '.tar.gz';

tar_command = "tar zcfP %s %s" % (target,' '.join(source));

if os.system(tar_command) == 0:
	print 'Successful backup to',target;
else:
	print 'Backup FAILED';

