from socket import *
import time
HOST, PORT = '', 50003
BUFSIZ = 1024

t = socket(AF_INET, SOCK_STREAM)
t.bind((HOST, PORT))
t.listen(5)
while True:
    tcpServer, add = t.accept()
    while True:
        data = tcpServer.recv(BUFSIZ)
        print data
        tcpServer.send('[%s]  %s' %(time.ctime(), data))
    tcpServer.close()
