#!/usr/bin/env python
#_*_ coding:utf-8 _*_
import sys
reload(sys)
sys.setdefaultencoding('utf-8')
import urllib, urllib2, re

URL = 'http://www.nongli.com/item3'
FILENAME = 'nongli.com.html'
try:

    request = urllib2.Request(URL)
    response = urllib2.urlopen(request)
    content = response.read().encode()
    print content
except urllib2.URLError, e:
    if hasattr(e, 'reason'):
        print e.reason

