#!/usr/bin/env python

'makeTextFile.py -- creat text file'

import os
ls = os.linesep
fname=''
while True:
    fname = raw_input('>')
    if os.path.exists(fname):
        print "Error: '%s' already exists" %fname
    else:
        break

all = []
print "\nEnter lines context (text) lines"

while True:
    entry = raw_input('>')
    if entry == '.':
        break
    else:
        all.append(entry)

fobj = open(fnam, 'w')
fobj.writelines(['%s%s' %(x, ls) for x in all])
fobj.close
print "Done"
