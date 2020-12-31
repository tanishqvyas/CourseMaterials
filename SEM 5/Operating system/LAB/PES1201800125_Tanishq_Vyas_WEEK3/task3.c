#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <sys/types.h>

int main(int argc, char* argv[])
{

	pid_t  pid;

	pid = fork();

	if(pid == 0)
	{
		printf("Child Process to execute Partial Sums and Products given in TASK 2 -----> \n\n");

		// Using exec command to execute another file
		char *args[]={"./partial.out",NULL}; 
        execvp(args[0],args);
	}

	else if (pid < 0)
	{
		printf("Child process creation failed\n");
	}

	else if (pid > 0)
	{
		// Using wait() so that parent waits for child process to exit before executing
		wait(NULL);
		printf("\n----\t Parent Process begins here \t----\n");
		printf("Parent process with id : %d,  having child with id :  %d\n", pid, getpid());

		printf("----\t Parent Process ends here \t----\n");

	}


	return 0;
}

