#/usr/bin/env python

MAXN = 100007
t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    L = map(int, input().split())
    A = [0 for i in range(MAXN)]
    for i in range(n):
        A[L[i]] += 1
    for i in range(1, n):
        A[i] = A[i] + A[i - 1]
    q = int(input())
    for i in range(q):
        a, b = map(int, input().split())
        print(A[b] - A[a - 1])

