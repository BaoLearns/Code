import socket

HOST = 'localhost'
PORT = 50003
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
while True:
    fileName = raw_input().strip()
    if len(fileName) == 0:
        continue
    s.send(fileName)
    context = s.recv(1024 * 1024)
    fp = open(fileName + '.back', 'w')
    fp.write(context)
    fp.close()
    print 'received\n', context
    print 'DONE'
s.close()
