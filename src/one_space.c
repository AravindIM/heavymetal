#include <stdio.h>
#define NONBLANK 'a'

int main()
{
    int c, lastc;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || lastc != ' ')
        {
            putchar(c);
        }
        lastc = c;
    }
}