import os
pid = os.fork()
if pid == 0:
    print 'i am in child, pid = %s, ppid = %s' %(os.getpid(), os.getppid())
else:
    print 'i am in father, pid = %s, cpid = %s' %(os.getpid(), pid)
