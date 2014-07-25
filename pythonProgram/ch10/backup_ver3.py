# !/usr/bin/python
# Filename:backup_ver2.py

import os;
import time;

source = ['/root/wangjin/pythonProgram/ch06'];

target_dir = '/root/wangjin/backup/'

today = target_dir + time.strftime('%Y%m%d');
now = time.strftime('%H%M%S');

comment = raw_input('Enter a comment --> ');

if len(comment) == 0:
	target = today + os.sep + now + '.tar.gz';
else:
	target = today + os.sep + now + '_' + comment.replace(' ','_') + '.tar.gz';

if not os.path.exists(today):
	os.mkdir(today);
	print 'Successfully created directory',today;

tar_command = "tar zcfP %s %s" % (target,' '.join(source));

if os.system(tar_command) == 0:
	print 'Successful backup to',target;
else:
	print 'Backup FAILED';

