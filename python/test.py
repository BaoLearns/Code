prime = [1 for i in xrange(10001)]
for i in xrange(2, 10001):
    if prime[i]:
        for j in xrange(2 * i, 10001, i):
            prime[j] = 0
ans = 0
n = int(raw_input())
for i in xrange(2, 10001):
    j = n - i
    if i != j and j > 2 and prime[i] and prime[j]:
        ans += 1
        print i, j
print ans / 2
