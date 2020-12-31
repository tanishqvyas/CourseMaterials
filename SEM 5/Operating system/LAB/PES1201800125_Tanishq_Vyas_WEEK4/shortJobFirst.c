#include <stdlib.h>
#include <stdio.h>


float find_average(int arr[], int size)
{
	float avg = 0;

	for (int i = 0; i < size; ++i)
	{
		avg += arr[i];
	}

	return avg/size;
}

void setZero(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = 0;
	}
}

int main() 
{
	printf("**************SHORTEST JOB FIRST**************\n\n");
	int numOfJobs;
	printf("Enter the number of Jobs : ");
	scanf("%d", &numOfJobs);


	int burstTime[numOfJobs];
	int jobID[numOfJobs];
	int isScheduled[numOfJobs];
	int waitingTime[numOfJobs];
	int turnAroundTime[numOfJobs];
	int timeElapsed = 0;
	int idx;

	setZero(isScheduled, numOfJobs);
	setZero(waitingTime, numOfJobs);
	setZero(turnAroundTime, numOfJobs);


	// Take Burst Time as input
	for (int i = 0; i < numOfJobs; ++i)
	{
		printf("Enter Job ID : ");
		scanf("%d", &jobID[i]);
		printf("Enter burst time for JOB (%d) : ", jobID[i]);
		scanf("%d", &burstTime[i]);
		printf("\n");
	}

	// Schedueling Code
	for (int i = 0; i < numOfJobs; ++i)
	{

		// Find next shortest job
		idx = 0;

		for (int j = 0; j < numOfJobs; ++j)
		{
			if(isScheduled[j] == 0)
			{
				idx = j;
				break;
			}
		}

		for (int k = 0; k < numOfJobs; ++k)
		{
			if(isScheduled[k] == 0)
			{
				if(burstTime[k] < burstTime[idx])
				{
					idx = k;
				}
			}
		}
		

		// Calc Corresponding values
		waitingTime[idx] = timeElapsed;
		turnAroundTime[idx] = waitingTime[idx] + burstTime[idx];
		isScheduled[idx] = 1;
		timeElapsed += burstTime[idx];

	}




	// Printing the Result
	printf("JobID\t Burst Time\t WaitingTime\t Turnaround Time\n");
	for (int i = 0; i < numOfJobs; ++i)
	{
		printf("%d\t %d\t\t %d\t\t %d\n", jobID[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
	}

	printf("\nAverage Waiting Time : %f", find_average(waitingTime, numOfJobs));
	printf("\nAvergae Turn Around Time : %f", find_average(turnAroundTime, numOfJobs));
	printf("\n");

	return 0;
}