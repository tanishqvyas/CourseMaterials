#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define BUFFER_SIZE 10

// Pre protocol declarations
void *Producer();
void *Consumer();

int product = 0;
int mutex_variable = 0;

void lock_MUTEX()
{
    mutex_variable = 1;
}

void free_MUTEX()
{
    mutex_variable = 0;
}


int main()
{
        pthread_t ptid, ctid;
        printf("\nMain Started");

        printf("BUFFER SIZE : %d\n\n", BUFFER_SIZE);

        pthread_create(&ptid, NULL, Producer, NULL);
        pthread_create(&ctid, NULL, Consumer, NULL);

        pthread_join(ptid, NULL);
        pthread_join(ctid, NULL);

        printf("\nMain done\n");
}

void *Producer()
{
        int products_produced = 0;

        printf("--------------------------------------------------");
        printf("\nProducer created");
        printf("\nProducer id is %ld\n", pthread_self()); //print thread id
        printf("--------------------------------------------------\n");
        // sleep(1);

        while (1)
        {
                if (product == BUFFER_SIZE)
                {
                        printf("Producer Sleeping. Buffer Limit Reached.\n");
                        sleep(1);
                }

                else if (product == 0 && mutex_variable == 0)
                {
                        lock_MUTEX();
                        ++product;
                        ++products_produced;
                        printf("Producing Product #%d \n", products_produced);
                        free_MUTEX();
                        sleep(1);
                }
        }
}

void *Consumer()
{
        int products_consumed = 0;
        printf("\n\n--------------------------------------------------");
        printf("\nConsumer created\n");
        printf("\nConsumer id is %ld\n", pthread_self());
        printf("--------------------------------------------------\n\n");

        while (1)
        {
                if (product > 0 && mutex_variable == 0)
                {
                        lock_MUTEX();
                        products_consumed++;
                        printf("Consuming Product #%d \n", products_consumed);
                        product--;
                        free_MUTEX();
                        sleep(1);
                }

                else if (product == 0)
                {
                        printf("Consumer Sleeping. No more products to consume.\n");
                        sleep(1);
                }
        }
}
