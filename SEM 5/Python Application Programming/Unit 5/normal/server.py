import socket

# Creating Socket Object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Binding socket
s.bind((socket.gethostname(), 1233))

'''
A socket is the end point that is used to send or recieve data
'''

# A queue of 5
s.listen(5)


while True:

	# Client socket obj, where they comin from
	clientsocket, address = s.accept()

	print(f"Connection from {address} has been established.")

	# Sending info to client
	clientsocket.send(bytes("Welcome to Server", "utf-8"))

	# Close the connection
	clientsocket.close()

