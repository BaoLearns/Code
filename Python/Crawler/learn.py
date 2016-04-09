#coding:utf-8
bar = 200
def foo():
    print 'calling foo()'
    bar = 100
    print 'in foo() bar is %s' %bar

foo()
foo()
print bar
#Íê³É
