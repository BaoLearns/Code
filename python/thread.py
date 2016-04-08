import threading
from time import sleep, ctime

class MyThread(threading.Thread):
    
    def __init__(self, func, args, name = ''):
        threading.Thread.__init__(self)
        self.func = func
        self.args = args
        self.name = name

    def getResult(self):
        return self.run
    
    def run(self):
        print 'starting ', self.name, " at ", ctime()
        apply(self.func, self.args)
        print self.name, " finlished at:", ctime()

def fib(n):
    sleep(0.005)
    if n < 2:
        return 1
    return fib(n - 1) + fib(n - 2)

def fac(n):
    sleep(0.1)
    if n < 2:
        return 1
    return n * fac(n - 1)

def sum(n):
    sleep(0.1)
    if n < 2:
        return 1
    return n + sum(n - 1)

funcs = [fib, fac, sum]
n = 12

def main():
    nfunc = range(len(funcs))
    print "Single THREAD...."
    for i in nfunc:
        print "starting ", funcs[i].__name__, " at ", ctime()
        print funcs[i](n)
        print funcs[i].__name__, " end at ", ctime()
    print "Mutiple THREAD...."
    threads = []
    for i in nfunc:
        t = MyThread(funcs[i], (n,), funcs[i].__name__)
        threads.append(t)
    for i in nfunc:
        threads[i].start()

    for i in nfunc:
        threads[i].getResult()
    while threading.activeCount() > 1:
        print threading.activeCount()
    print 'all DONE'

if __name__ == '__main__':
    main()
