'''
x = int(raw_input())
numbers = xrange(x)
for i in xrange(1 << x):
    flag = False
    for j in xrange(x):
        if (i >> j) & 1:
            print numbers[j],
            flag = True
    if flag:
        print ''
'''

x = int(raw_input())
numbers = xrange(x)
Hash = [1 for i in xrange(x)]
result = [0 for i in xrange(x)]
def foo(x, n):
    if n == x:
        for i in xrange(x):
            print result[i],
        print ''
        return None
    for i in xrange(x):
        if Hash[i] == 1:
            Hash[i] = 0
            result[n] = i
            foo(x, n + 1)
            Hash[i] = 1
foo(x, 0)
