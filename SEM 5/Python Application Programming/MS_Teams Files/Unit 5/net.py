#networking in python
#client - any piece of hardware or software requesting for something
#server - any hardware or software responding to a request

#ATM machine
"""
import socket
hostname=socket.gethostname()
ip=socket.gethostbyname(hostname)
print(hostname)
print(ip)
"""

#socket module
#  s=socket.socket(socket_family,socket_type,protocol)
"""
import socket
for host in ['www.python.org','www.pes.edu','nosuchname']:
	try:
		print(host,socket.gethostbyname(host)) #returns ip address of the host
	except socket.error as msg:
		print(host,msg)
"""

#gethostbyname_ex() #more information about the server
"""
import socket
for host in ['www.python.org','www.pes.edu','nosuchname']:
	print(host)
	try:
		hostname,aliases,address=socket.gethostbyname_ex(host)
		print('hostname',hostname)
		print('aliases',aliases)
		print('address',address)
	except socket.error as msg:
		print('error:',msg)
print

"""

"""
import socket
from urllib.parse import urlparse
for url in ['http://www.python.org',#web pages 80 
		'ftp://prep.ai.mit.edu',#file tranfer 20
		'gopher://gopher.micro.umn.edu',#document tranfer 70
		'smtp://mail.example.com',#sending emails 25
		'imap://mail.example.com',#fetching email 143
		'pop3://pop.example.com' #fetching email 110
		]:
	parsed_url=urlparse(url)
	port=socket.getservbyname(parsed_url.scheme)
	print(parsed_url.scheme,port)


"""
"""
given list of ports print their corresponding protocol

ex: given list [80,25] output [http,smp]

"""
"""
s.bind()
s.listen()
s.accept()

cleint

s.connect()

#psuedocode for the server
while True:
	accept a request()
	open_connection()
	while connection_exsits():
		receive()
		respond()
close_connection()

client
#psuedocode for the client
get_the_server_add()
request_connection()
while connected:
	send_request()
	get_responses()
close_connection()

"""

#connection oriented tcp, connection less udp


















