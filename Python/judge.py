import time
import random
from functools import wraps

def fn_timer(function):
    @wraps(function)
    def function_timer(*args, **kwargs):
        t0 = time.time()
        result = function(*args, **kwargs)
        t1 = time.time()
        print "Total time running %s: %s seconds." % (function.func_name, str(t1 - t0))
        return result
    return function_timer

@fn_timer
def random_sort(n):
    return sorted([random.random() for i in xrange(n)])


import sys
random_sort(int(sys.argv[1]))
