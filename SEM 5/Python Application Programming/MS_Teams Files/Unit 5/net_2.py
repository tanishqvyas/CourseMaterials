"""#getaddrinfo()

import socket
def get_const(prefix):
	return dict((getattr(socket, n), n)
	for n in dir(socket)
	if n.startswith(prefix)
	)
families=get_const('AF_')
#print(families)
types=get_const('SOCK_')
protocols=get_const('IPPROTO_')
for response in socket.getaddrinfo('www.pes.edu',"http"):
#unpacke the response tuple
	family,socktype,protocol,canonname,sockaddr=response
	print('family:',families[family])
	print('type:',types[socktype])
	print('protocol:',protocols[protocol])
	print('canonical name:',canonname)
	print('socket address:',sockaddr)
	print()
"""
"""
#server
import socket
s=socket.socket()
host=socket.gethostname()
port=12345
s.bind(host,port))
s.listen(2)
while True:
	c,address=s.accept()
	print('got the connection from',addr)
	output='thank you'
	c.sendall(output.encode('utf-8'))
	c.close()

#client

import socket
s=socket.socket()
host=s.gethostname()
port=12345
s.connect((host,port))
print(s.recv(1024))
s.close()

import socket
import os
import threading

ServerSocket = socket.socket()
host = '127.0.0.1'
port = 1234
ThreadCount = 0
try:
    ServerSocket.bind((host, port))
except socket.error as e:
    print(str(e))

print('Waitiing for a Connection..')
ServerSocket.listen(5)


def threaded_client(connection):
    connection.send(str.encode('Welcome to the Server\n'))
    while True:
        data = connection.recv(2048)
        reply = 'Server Says: ' + data.decode('utf-8')
        if not data:
            break
        connection.sendall(str.encode(reply))
    connection.close()

while True:
    Client, address = ServerSocket.accept()
    print('Connected to: ' + address[0] + ':' + str(address[1]))
    threading.Thread(target=threaded_client, args=(Client, ))
    ThreadCount += 1
    print('Thread Number: ' + str(ThreadCount))
ServerSocket.close()

"""
#server(UDP)

from socket import *
from time import ctime
host=socket.gethostname()
port=12346
bufsize=1024
addr=(host,port)

udpsersocket=socket(AF_INET,SOCK_DGRAM)
udsersocket.bind(addr)
while True:
	print("waiting")
	data,addr=recvfrom(bufsize)
	udpsersocket.sendto(bytes(data.decode("utf-8")),"utf-8"),addr)
	print("received from and returned to:",addr)
udpservsock.close()




































