#!/usr/bin/python
# Filename:htmlparser_1.py

import urllib;
import urlparse;
import HTMLParser;

class CheckHTML(HTMLParser.HTMLParser):
	available = True;
	def handleData(self,data):
		if"404 Not Found" in data or "Error 404" in data:
			self.available = False;

checkUrls = ["index","test","help","news","faq","download"];

for url in checkUrls:
	newUrl = urlparse.urljoin("http://www.baidu.com/",url);
	fp = urllib.urlopen(newUrl);
	data = fp.read();
	fp.close();

	p = CheckHTML();
	p.feed(data);
	p.close();

	if p.available:
		print newUrl," ==> OK";
	else:
		print newUrl," ==> Not Found";

