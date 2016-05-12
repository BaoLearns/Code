#/usr/bin/env python

'''
    description:
    author:
    date:

'''

class HEAP(object):
    '''
    '''
    def __init__(self, array = []):
        A = array
        length = len(A) - 1
        print A, length

    def LEFT(self, i):
        return i * 2

    def RIGHT(self, i):
        return i * 2 + 1

    def MAX_HEAPIFY(self, i):
        print 'xx'
        l = LEFT(i)
        r = RIGHT(i)
        largest = i
        if l <= self.length and self.A[largest] < self.A[l]:
            largest = l
        if r <= self.length and self.A[largest] < self.A[r]:
            largest = r
        if largest != i:
            self.A[i], self.A[largest] = self.A[largest], self.A[i]
            MAX_HEAPIFY(largest)

    def BULID_MAX_HEAPIFY(self):
        for i in xrange(self.length / 2, 0, -1):
            MAX_HEAPIFY(i)

    def HEAPSORT(self):
        for i in xrange(self.length, 1, -1):
            self.A[1], self.A[self.length] = self.A[length], self.A[1]
            self.length -= 1
            MAX_HEAPIFY(1)
    def OUTPUT(self):
        for i in xrange(1, len(self.A)):
            print self.A[i],

if __name__ == '__main__':
    A = [0, 1, 2, 5, 2, 2, 12, 45, 17, 20]
    Heap = HEAP(A)
    Heap.BULID_MAX_HEAPIFY()
    Heap.HEAPSORT()
    Heap.OUTPUT()
