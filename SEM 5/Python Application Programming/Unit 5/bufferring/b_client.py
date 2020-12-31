import socket

HEADER_SIZE = 10


# Creating Socket Object  | ipv4, TCP
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connecting to the port
s.connect((socket.gethostname(), 1236))


# This TCP socket is stream of data
# Thus we decide how big chunks do we want to 
# recieve at a time
# here  is gd enf

while True:

	full_msg = ''
	new_msg = True


	while True:

		msg = s.recv(8)

		if new_msg:
			print(f"New message length : {msg[:HEADER_SIZE]}")
			msg_len = int(msg[:HEADER_SIZE])
			new_msg = False



		full_msg += msg.decode("utf-8")

		if(len(full_msg) - HEADER_SIZE == msg_len):
			print("Full message Received")
			print(full_msg[HEADER_SIZE:])
			new_msg = True
			full_msg = ""

	print(full_msg)
