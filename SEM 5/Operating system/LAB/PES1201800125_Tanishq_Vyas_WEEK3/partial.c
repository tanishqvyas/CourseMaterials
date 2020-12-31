#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{

	int numbers[] = {1,2,3,4,5,6,7,8,9,10};
	int arrLength = 10;
	
	int answer[10];
	answer[0] = numbers[0];

	printf("The numbers are : \n");
	for (int i = 0; i < arrLength; ++i)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n\n");

	pid_t  pid;

	pid = fork();

	if(pid == 0)
	{

		printf("\nChild process to calculate Partial Sum of numbers");

		for (int i = 1; i < arrLength; ++i)
		{
			answer[i] = answer[i-1] + numbers[i];
		}

		printf("\nThe Partial Sum is :\n");
		for (int i = 0; i < arrLength; ++i)
		{
			printf("%d ", answer[i]);
		}
		printf("\n");
	}

	else if (pid < 0)
	{
		printf("\nChild process creation failed\n");
	}

	else if (pid > 0)
	{
		printf("Parent process with id : %d,  having child with id :  %d", pid, getpid());

		for (int i = 1; i < arrLength; ++i)
		{
			answer[i] = answer[i-1] * numbers[i];
		}

		printf("\nThe Partial Product is :\n");
		for (int i = 0; i < arrLength; ++i)
		{
			printf("%d ", answer[i]);
		}
		printf("\n");
	}


	return 0;
}