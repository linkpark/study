#!/usr/bin/python
# Filename: urlparse_1.py

import urlparse;
absUrls = ["http://www.python.org0","ftp://www.linux.org","http://www.gtk.org","file://"];
relUrl = "fag.html"

for absUrl in absUrls:
	url = urlparse.urljoin(absUrl,relUrl);
	expectedUrl = url;
	scheme,netloc,path,query,fragment = urlparse.urlsplit(url)
	
	print scheme,netloc,path,query,fragment;

	if scheme and scheme == "file":
		print url,"=== > None";
		continue;
	
	if scheme is not "ftp":
		expectedUrl = urlparse.urlunsplit(('http',netloc,path,query,fragment));

	print url,"=== >",expectedUrl;


