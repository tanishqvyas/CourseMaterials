#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int main(int argc, char const *argv[])
{
    
    int num_of_segments = 0, num_processes = 0;
    printf("Enter the number of Memory Segments : ");
    scanf("%d", &num_of_segments);

    int memory[num_of_segments];

    printf("\nEnter the values:\n");
    for (int i = 0; i < num_of_segments; i++)
    {
        printf("Enter the partition size : ");
        scanf("%d", &memory[i]);
        printf("\n");
    }
    
    printf("\nEnter the numer of processes to be assigned : ");
    scanf("%d", &num_processes);
    printf("\n");

    char process[num_processes][10];
    int process_size[num_processes];
    int is_occupied[num_of_segments];

    for (int i = 0; i < num_of_segments; i++)
    {
        is_occupied[i] = -1;
    }

    for (int i = 0; i < num_processes; i++)
    {
        printf("Enter the Name of process : ");
        scanf("%s", process[i]);
        printf("Enter the size of the process : ");
        scanf("%d", &process_size[i]);
        printf("\n");
    }


    // Doing Best Fit Algorithm 
    for (int i = 0; i < num_processes; i++)
    {
        int cur_diff;
        int min_diff = INT_MAX;
        int min_diff_idx = -1;

        // Check all memory slots
        for(int j = 0; j < num_of_segments; j++)
        {
            if(is_occupied[j] == -1)
            {
                cur_diff = memory[j] - process_size[i];

                // Process bigger than partition
                if(cur_diff < 0)
                {
                    continue;
                }

                else
                {
                    if(cur_diff < min_diff)
                    {
                        min_diff_idx = j;
                        min_diff = cur_diff;
                    }
                }
                
            }
        }

        // Process too big
        if(min_diff_idx  == -1)
        {
            printf("Process %s with size %d is bigger than all partition sizes.\n", process[i], process_size[i]);
        }

        else
        {
            // Set which process has occupied it
            is_occupied[min_diff_idx] = i;

            // Reduce memory availability
            memory[min_diff_idx] = min_diff;

        }
        
    }



    // Printing the final stuff
    printf("Partition No.\tPartition Size\tPartition Status\tFragment Size\n");
    for (int i = 0; i < num_of_segments; i++)
    {   

        // printf("is_occupied : %d\n", is_occupied[i]);

        if(is_occupied[i] == -1)
        {
            printf("%d\t\t%d\t\tFree\n", i, memory[i]);
        }

        else
        {
            printf("%d\t\t%d\t\tallocated<%s>\t\t%d\n", i, memory[i] + process_size[is_occupied[i]], process[is_occupied[i]] ,memory[i]);
        }
    }



    return 0;
}
