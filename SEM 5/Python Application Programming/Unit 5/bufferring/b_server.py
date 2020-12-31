import socket

# We make use of header to ensure proper buffering
HEADER_SIZE = 10

# Creating Socket Object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Binding socket
s.bind((socket.gethostname(), 1236))


# A socket is the end point that is used to send or recieve data


# A queue of 5
s.listen(5)
print("Server is listening....")


while True:

	# Client socket obj, where they comin from
	clientsocket, address = s.accept()

	print(f"Connection from {address} has been established.")

	# The message
	msg = "Welcome to the Server"

	# The header + msg
	# Header is used to tell how long a msg is n stuff
	msg = f"{len(msg):<{HEADER_SIZE}}"+msg


	# Sending info to client
	clientsocket.send(bytes(msg, "utf-8"))

