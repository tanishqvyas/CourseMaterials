#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 9

int main(int argc, char const *argv[])
{
	printf("Buffer Size : %d\n\n", BUFFER_SIZE);
	int pd[2];

	if(pipe(pd) < 0)
	{
		exit(1);
	}

	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		char t = i+1  + '0';
		char *msg = &t;

		write(pd[1], msg, BUFFER_SIZE);
		printf("Producer Produced : %s\n", msg);
	}


	for(int j = 0; j < BUFFER_SIZE; j++)
	{
		char received[BUFFER_SIZE];
		read(pd[0], received, BUFFER_SIZE);
		printf("Consumer Consumed : %s\n", received);
	}	

	return 0;
}
