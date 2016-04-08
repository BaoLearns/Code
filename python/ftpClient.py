import SocketServer
import socket

HOST, PORT = 'localhost', 50003
BUFSIZ = 1024
tcpClient = socket.socket(socket.AF_INET, sockeet.SOCK_STREAM)
tcpClient.connect((HOST, PORT))
while True:
    data = raw_input('>')
    tcpClient.send(data)
    data = tcpClient.recv(BUFSIZE)
    print 'Recrived ', data
tcpClient.close()
