#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

#define BILLION 1000000000UL
#define NUM_THREADS 2

uint32_t counter = 0;

void *count_to_billion(void *ptr);

int main()
{
    int i;
    pthread_t thread_id[NUM_THREADS];
    for (i = 0; i < NUM_THREADS; ++i)
    {
        if (pthread_create(&thread_id[i], NULL, &count_to_billion, NULL) != 0)
        {
            perror("Failed to create thread");
        }
    }
    for (i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(thread_id[i], NULL);
    }
    printf("Result: %d\n", counter);
    exit(0);
}

void *count_to_billion(void *ptr)
{
    for (uint32_t i = 0; i < BILLION; ++i)
    {
        ++counter;
    }
}