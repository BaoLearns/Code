#!/bin/usr/env python
'''
    title: find maximum subarray
    date: 2016-04-18
    author: oliver bao
    description: given a interge array, find maximum successive subarray.
'''


INF = -100000007   # min value

def find_max_crossing_subarray(Array, low, mid, high):
    '''
        description:
    '''
    left_sum = INF
    SUM = 0
    for index in xrange(mid, low - 1, -1):
        SUM += Array[index]
        if SUM > left_sum:
            left_sum = SUM
            max_left = index
    right_sum = INF
    SUM = 0
    for index in xrange(mid + 1, high + 1):
        SUM += Array[index]
        if SUM > right_sum:
            right_sum = SUM
            max_right = index
    return [max_left, max_right, left_sum + right_sum]

def find_maximum_subarray(Array, low, high):
    if low == high:
        return [low, high, Array[low]]
    mid = low + (high - low) / 2
    # left: low to mid
    left_low, left_high, left_sum = find_maximum_subarray(Array, low, mid)
    # right: mid + 1 to high
    right_low, right_high, right_sum = find_maximum_subarray(Array, mid + 1, high)
    # mid: query low <= i <= mid <= j <= high
    cross_low, cross_high, cross_sum = find_max_crossing_subarray(Array, low, mid, high)
    if left_sum >= right_sum and left_sum >=  cross_sum:
        return [left_low, left_high, left_sum]
    if right_sum >= left_sum and right_sum >=  cross_sum:
        return [right_low, right_high, right_sum]
    if cross_sum >= left_sum and cross_sum >=  right_sum:
        return [cross_low, cross_high, cross_sum]

Ans = find_maximum_subarray(L, 0, len(L) - 1)
print Ans[2]





