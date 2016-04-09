'''import re
fp = open('hello.txt', 'r')
fp2 = open('hello2.txt', 'w')
context = fp.readlines()
count = 0
for i in context:
    fp2.write(i.replace('hello', 'fuck'))
print count
fp.close()
fp2.close()'''

import re

fp = open("hello.txt", 'r+')
context = fp.readlines()
fp.seek(0, 0)
for i in context:
    fp.write(i.replace('fuck', 'hello'))
fp.close()
