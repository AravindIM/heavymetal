#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

int count = 0;

void *count_odd(void *ptr);
void *count_even(void *ptr);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int main()
{
    pthread_t odd_thread, even_thread;

    if (!pthread_create(&odd_thread, NULL, &count_odd, NULL))
    {
        perror("Failed to create odd thread");
    }

    if (!pthread_create(&even_thread, NULL, &count_even, NULL))
    {
        perror("Failed to create odd thread");
    }

    pthread_join(odd_thread, NULL);
    pthread_join(even_thread, NULL);

    return 0;
}

void *count_odd(void *ptr)
{
    while (count < MAX)
    {
        pthread_mutex_lock(&mutex);
        while (count % 2 != 1)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d\n", count);
        ++count;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
}

void *count_even(void *ptr)
{
    while (count < MAX)
    {
        pthread_mutex_lock(&mutex);
        while (count % 2 != 0)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d\n", count);
        ++count;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
}