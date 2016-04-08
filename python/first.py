#!/usr/bin/env python
print ("hello world!")
if True:
    print 'bababa'
name = "LBAO"
age = 10
print type(name)
print type(age)
name = raw_input('plese input you name ')
age = int(raw_input('plese input you age '))
sex = raw_input('plese input you sex ')
job = raw_input('plese input you job ')
print '''
        %s
        %d
        %s
        %s
'''%(name, age, sex, job)
print "sdfsdf" "fdf"
if age < 18:
    print "You are boy"
elif age > 60:
    print "Your are old boy"
else:
    print "adult"
