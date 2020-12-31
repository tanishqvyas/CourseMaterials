a.out: client.o server.o
	gcc client.o server.o -o a.out

client.o: client.c server.c header.h
	gcc -c client.c

server.o: server.c
	gcc -c server.c