import SocketServer
import os

class MyTCPHandler(SocketServer.BaseRequestHandler):
    def handler(self):
        self.data = self.request.recv(1024).strip()
        print "[%s] Welcome my server" %self.client_address
        print self.data
        self.request.sendall("i'm fine!")

HOST, PORT = '', 50003
tcpServer = SocketServer.ThreadingTCPServer((HOST, PORT), MyTCPHandler)
tcpServer.serve_forever()
