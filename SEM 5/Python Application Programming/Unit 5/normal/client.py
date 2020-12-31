import socket

# Creating Socket Object  | ipv4, TCP
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connecting to the port
s.connect((socket.gethostname(), 1233))


# This TCP socket is stream of data
# Thus we decide how big chunks do we want to 
# recieve at a time
# here  is gd enf

full_msg = ""

while True:

	msg = s.recv(8)

	if(len(msg) <= 0):
		break
	else:
		full_msg += msg.decode("utf-8")

print(full_msg)
