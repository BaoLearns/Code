import math
a = str(raw_input())
b = str(raw_input())
Map = {}
def solve():
    lena = len(a)
    lenb = len(b)
    print a, b, lena - lenb
    ans = 0
    for i in xrange(lena - lenb + 1 ):
        st = ''
        for j in xrange(lenb):
            st += a[i]
        if Map.has_key(st):
            ans += Map[st]
        else:
            num = 0
            for j in xrange(lenb):
                num += abs(int(st[j]) - int(b[j]))
            ans += num
            Map[st] = num
        print st
    print ans
if len(a) > len(b):
    solve()
else:
    c = a
    a = b
    b = c
    solve()
