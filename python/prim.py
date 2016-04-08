prim = [True for i in xrange(101)]
for i in xrange(2, 101, 1):
    if prim[i]:
        for j in xrange(i + i, 101, i):
            prim[j] = False
ans = []
for i in xrange(2, 101, 1):
    if prim[i]:
        ans.append(i)

print ' '.join([str(i) for i in ans])
