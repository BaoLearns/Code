#!/usr/bin/env python
import SocketServer

class MyTCPHandler(SocketServer.BaseRequestHandler):
    def handle(self):
        while True:
            self.data = self.request.recv(1024).strip()
            print "{} wrote:".format(self.client_address[0])
            print self.data
            self.request.sendall(self.data.upper())
        print '%s is dead!' %self.client_address[0]
if __name__ == '__main__':
    HOST, PORT = 'localhost', 50003
    server = SocketServer.ThreadingTCPServer((HOST, PORT), MyTCPHandler)
    server.serve_forever()
