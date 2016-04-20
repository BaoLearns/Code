MAX = 10000007

def merge(Array, l, q, r):
    L, R = [], []
    for i in xrange(l, q + 1):
        L.append(Array[i])
    for i in xrange(q + 1, r + 1):
        R.append(Array[i])
    L.append(MAX)
    R.append(MAX)
    i, j = 0, 0
    for k in xrange(l, r + 1):
        if L[i] <= R[j]:
            Array[k] = L[i]
            i += 1
        else:
            Array[k] = R[j]
            j += 1

def merge_sort(Array, l, r):
    if l < r:
        q = (l + r) / 2
        merge_sort(Array, l, q)
        merge_sort(Array, q + 1, r)
        merge(Array, l, q, r)

if __name__ == '__main__':
    Array = map(int, raw_input().split())
    merge_sort(Array, 0, len(Array) - 1)
    for v in Array:
        print v,
