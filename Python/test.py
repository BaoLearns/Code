# -*- coding:utf-8 -*-
import os, re

fp = os.popen('dir', 'r')
for eachLine in fp.readlines():
    print re.split(r'\s+', eachLine.strip())
fp.close()
print u'我是个男孩'
def foo(x):
    print 'x = %s' %x
