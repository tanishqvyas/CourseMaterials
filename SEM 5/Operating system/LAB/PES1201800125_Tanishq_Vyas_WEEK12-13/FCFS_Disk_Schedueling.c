#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 


int main(int argc, char const *argv[])
{
    int range, queue_size, cur_pos, cur_seek_time, total_seek_time = 0;
    
    printf("Enter the max range of disk : ");
    scanf("%d", &range);
    printf("Enter the queue size : ");
    scanf("%d", &queue_size);

    int req_queue[queue_size];
    printf("Enter the queue of disk portions to be read : ");
    for (int i = 0; i < queue_size; i++)
    {
        scanf("%d ", &req_queue[i]);
    }
    int hold;
    scanf("%d", &hold);
    printf("Enter the initial head position : ");
    scanf("%d", &cur_pos);


    // FCFS Disk Schedueling
    for (int i = 0; i < queue_size; i++)
    {
        cur_seek_time = abs(req_queue[i] - cur_pos);
        printf("Disk head moves from %d to %d with seek time %d\n", cur_pos, req_queue[i], cur_seek_time);
        cur_pos = req_queue[i];
        total_seek_time += cur_seek_time;
    }
    printf("Total Seek Time is : %d\n", total_seek_time);
    float avg_seek_time = total_seek_time/(float)queue_size;
    printf("Average Seek Time is %.6f\n", +avg_seek_time);
    
   

    return 0;
}
