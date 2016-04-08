import socket, os

HOST = ''
PORT = 50003
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(5)
while True:
    conn, addr = s.accept()

    print 'Connected by ', addr

    while True:
        command = conn.recv(1024)
        if not command:
            break
        fp = open(command, 'r')
        context = fp.readlines()
        fp.close()
        conn.sendall(str(context))
    conn.close()
    print 'Free by ', addr
