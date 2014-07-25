#!/usr/bin/python
# Filename: urlParse.py

import urlparse;

r = urlparse.urlparse('http://www.baidu.com');
print r;

print r.scheme;
print r.netloc;
print r.path;
