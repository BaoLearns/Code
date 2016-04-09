#!/usr/bin/env python

'readTextFile -- read and display text file'

import os

fname = raw_input('Enter filename')

print
try:
    fobj = open(fname, 'r')
except IOError, e:
    print "*** file open error:", e
else:
    for eachLine in fobj:
        print eachLine,
    fobj.close()
