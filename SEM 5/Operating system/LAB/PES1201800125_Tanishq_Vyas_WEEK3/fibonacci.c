#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{

	pid_t  pid;

	pid = fork();

	int first = 0;
	int second = 1;

	if(pid == 0)
	{
		printf("Child process to calculate fibonacci numbers\n");

		printf("%d\n%d\n",first, second);
		for (int i = 0; i < atoi(argv[1]) - 2; ++i)
		{
			int hold = second;
			second = first + second;
			first = hold;
			printf("%d\n",second);
		}
	}

	else if (pid < 0)
	{
		printf("Child process creation failed\n");
	}

	else if (pid > 0)
	{
		printf("Parent process with id : %d,  having child with id :  %d\n", pid, getpid());
	}


	return 0;
}