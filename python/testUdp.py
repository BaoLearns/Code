#/usr/bin/env python

from socket import *
from time import ctime

HOST = ''
PORT = 21567
BUFSIZ = 1024
ADDR = (HOST, PORT)

udpSerSock = socket(AF_INET, SOCK_DGRAM)
udpSerSock.bind(ADDR)

while True:
    print 'waiting for message...'
    data, udpCliSock = udpSerSock.recvfrom(BUFSIZ)
    udpSerSock.sendto('[%s] %s' %(ctime(), data))
    print '...received from and return to:', addr
udpSerSock.close()
