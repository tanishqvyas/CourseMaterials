#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
#define NUM_PHILOSOPHERS 5


// Binary Semaphores to keep track of Philosopher
int chopsticks[NUM_PHILOSOPHERS];

// Functions for philosophers
void *philosopher_behaviour(void* id)
{   
    int philosopher_number = *((int*)id);

    // Endless loop for philosopher
    while(1)
    {
        // Thinking Section
        printf("PID : (%ld)  Philosopher %d is THINKING\n", pthread_self(), philosopher_number+1);
        sleep(1);
        
        // Hungry Section
        printf("PID : (%ld)  Philosopher %d is Hungry\n", pthread_self(), philosopher_number+1);

        // Philosopher khaan Paan section
        while(1)
        {
            // Entry Section : Check for Chopsticks Availability
            // Check n pick left chopstick
            if(chopsticks[philosopher_number] == 1)
                continue;            
            // check n pick right Chopstick
            if(chopsticks[(philosopher_number+1)%NUM_PHILOSOPHERS] == 1)
                continue;

            chopsticks[philosopher_number] = 1;
            chopsticks[(philosopher_number+1)%NUM_PHILOSOPHERS] = 1;

            printf("PID : (%ld)  Philosopher %d picks #%d and #%d chopsticks up\n", pthread_self(), philosopher_number+1, philosopher_number+1, 1 + ((philosopher_number+1)%NUM_PHILOSOPHERS));

            // Khao Noodles Pel kr k
            printf("PID : (%ld)  Philosopher %d is Eating Noodles\n", pthread_self(), philosopher_number+1);
            sleep(1);

            // EXIT Section : Free the Chopsticks
            chopsticks[philosopher_number] = 0;
            chopsticks[(philosopher_number+1)%NUM_PHILOSOPHERS] = 0;
            
            printf("PID : (%ld)  Philosopher %d puts #%d and #%d chopsticks down\n", pthread_self(), philosopher_number+1, philosopher_number+1, 1 + ((philosopher_number+1)%NUM_PHILOSOPHERS));
            break;
        }
    }
}

void *philosopher_behaviour_rev(void* id)
{
    int philosopher_number = *((int*)id);

    // Endless loop for philosopher
    while(1)
    {
        // Thinking Section
        printf("PID : (%ld)  Philosopher %d is THINKING\n", pthread_self(), philosopher_number+1);
        sleep(1);
        
        // Hungry Section
        printf("PID : (%ld)  Philosopher %d is Hungry\n", pthread_self(), philosopher_number+1);

        // Philosopher khaan Paan section
        while(1)
        {
            // Entry Section : Check for Chopsticks Availability

            // check n pick right Chopstick
            if(chopsticks[(philosopher_number+1)%NUM_PHILOSOPHERS] == 1)
                continue;

            // Check n pick left chopstick
            if(chopsticks[philosopher_number] == 1)
                continue;            
            
            chopsticks[(philosopher_number+1)%NUM_PHILOSOPHERS] = 1;
            chopsticks[philosopher_number] = 1;

            printf("PID : (%ld)  Philosopher %d picks #%d and #%d chopsticks up\n", pthread_self(), philosopher_number+1, philosopher_number+1, 1 + ((philosopher_number+1)%NUM_PHILOSOPHERS));

            // Khao Noodles Pel kr k
            printf("PID : (%ld)  Philosopher %d is Eating Noodles\n", pthread_self(), philosopher_number+1);
            sleep(1);

            // EXIT Section : Free the Chopsticks
            chopsticks[philosopher_number] = 0;
            chopsticks[(philosopher_number+1)%NUM_PHILOSOPHERS] = 0;
            
            printf("PID : (%ld)  Philosopher %d puts #%d and #%d chopsticks down\n", pthread_self(), philosopher_number+1, philosopher_number+1, 1 + ((philosopher_number+1)%NUM_PHILOSOPHERS));

            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    // Declare thread array
    pthread_t thread_ids[NUM_PHILOSOPHERS];
    int philosopher_numbers[NUM_PHILOSOPHERS];
    
    // Setting the Philosopher Numbers
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        philosopher_numbers[i] = i;
    }

    // Setting the state of all Chopsticks as 0
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        chopsticks[i] = 0;
    }

    // Thread Creation
    for (int i = 0; i < NUM_PHILOSOPHERS-1; i++)
    {
        pthread_create(&thread_ids[i], NULL, philosopher_behaviour, (void*)&philosopher_numbers[i]); 
    }

    // Reversing the last philosopher to avoid cyclic wait
    pthread_create(&thread_ids[NUM_PHILOSOPHERS-1], NULL, philosopher_behaviour_rev,(void*) &philosopher_numbers[NUM_PHILOSOPHERS-1]); 

    // Wait equivalent
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_join(thread_ids[i], NULL); 
    }

    exit(0);
}
