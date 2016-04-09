from socket import *

HOST, PORT = 'localhost', 50003
BUFSIZ = 1024

while True:
    tcpClient = socket(AF_INET, SOCK_STREAM)
    tcpClient.connect((HOST, PORT))

    data = raw_input('>')
    tcpClient.send(data)
    data = tcpClient.recv(1024)
    print data

tcpClient.close()
