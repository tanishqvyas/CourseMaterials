#include <stdio.h>
#include <stdlib.h>


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
	
	printf("********************ROUND ROBIN SCHEDULING**********************\n");
	printf("\n");

	int numOfJobs;
	printf("Enter number of Jobs : ");
	scanf("%d", &numOfJobs);
	printf("\n");


	int burstTime[numOfJobs];
	int turnAroundTime[numOfJobs];
	int remainingTime[numOfJobs];
	int waitingTime[numOfJobs];
	char name[numOfJobs][100];

	int timeElapsed = 0;
	int numProcessFinished = 0;
	int timeQuanta;


	setZero(turnAroundTime, numOfJobs);
	setZero(waitingTime, numOfJobs);

	// Reading input for each process
	for (int i = 0; i < numOfJobs; ++i)
	{
		printf("Enter the name of process : ");
		scanf("%s", name[i]);
		printf("Enter CPU burst time : ");
		scanf("%d", &burstTime[i]);
		remainingTime[i] = burstTime[i];
		printf("\n");
	}


	// Finding approrpiate Time Quanta
	printf("Enter time quantum : ");
	scanf("%d", &timeQuanta);
	printf("\n");

	// Process Index manager
	int cur_idx = 0;

	// Calculating the values	
	while (numProcessFinished < numOfJobs)
	{
		if(remainingTime[cur_idx] == 0)
		{
			cur_idx = (cur_idx + 1)%numOfJobs;
			continue;
		}
		else
		{
			int iter_strt_time = timeElapsed;

			if(remainingTime[cur_idx] - timeQuanta <=0)
			{

				timeElapsed += remainingTime[cur_idx];
				remainingTime[cur_idx] = 0;
				numProcessFinished++;
			}

			else
			{
				remainingTime[cur_idx] -= timeQuanta;
				timeElapsed += timeQuanta;
			}

			// Increasing waiting time for others
			for(int k = 0; k < numOfJobs; k++)
			{
				if(remainingTime[k] > 0)
				{
					if(k != cur_idx)
					{
						waitingTime[k] += (timeElapsed - iter_strt_time);
					}
				}
			}

			
		}

		// increasing index
		cur_idx = (cur_idx + 1)%numOfJobs;


	}


	// Printing the Result
	printf("Process\t Burst Time\t WaitingTime\t Turnaround Time\n");
	for (int j = 0; j < numOfJobs; ++j)
	{
		turnAroundTime[j] = burstTime[j] + waitingTime[j];
		printf("%s\t %d\t\t %d\t\t %d\n", name[j], burstTime[j], waitingTime[j], turnAroundTime[j] );
	}

	printf("\nAverage Waiting Time : %f", find_average(waitingTime, numOfJobs));
	printf("\nAvergae Turn Around Time : %f", find_average(turnAroundTime, numOfJobs));
	printf("\n");

	return 0;
}