# UDP Client

from socket import *
import sys

serverName = sys.argv[1]
serverPort = int(sys.argv[2])
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = input("Input lowercase sentence: ")
clientSocket.sendto(str.encode(message),(serverName, serverPort))
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print("Modified Message: ", modifiedMessage.decode())
clientSocket.close()