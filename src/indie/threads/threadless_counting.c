#include <stdio.h>
#include <stdlib.h>

#define MILLION 1000000

int counter = 0;

void count_to_million();

int main()
{
    count_to_million();
    printf("Result: %d\n", counter);
    exit(0);
}

void count_to_million()
{
    while (counter < MILLION)
    {
        counter++;
    }
}