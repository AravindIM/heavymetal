#include <stdio.h>
#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0
#define LOWER_SENTINEL -1

int main()
{
    int c, hist_index, state, i, overflow;
    int hist[MAXWORD];
    int maxvalue;
    int len;

    state = OUT;
    hist_index = LOWER_SENTINEL;
    overflow = 0;

    /* initialize the histogram*/
    for (i = 0; i < MAXWORD; ++i)
    {
        hist[i] = 0;
    }

    /* Set value for histogram */
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN)
            {
                state = OUT;
                if (hist_index < MAXWORD)
                    ++hist[hist_index];
                else
                    ++overflow;
            }
        }
        else
        {
            if (state == OUT)
            {
                state = IN;
                hist_index = LOWER_SENTINEL;
            }
            ++hist_index;
        }
    }

    /* Find the max value to scale the histogram */
    for (i = 0; i < MAXWORD; ++i)
    {
        if (hist[i] > maxvalue)
            maxvalue = hist[i];
    }

    /* Draw the histogram */
    for (i = 0; i < MAXWORD; ++i)
    {
        printf("\n%5d - %5d : ", i + 1, hist[i]);
        if (hist[i] > 0)
        {
            if ((len = hist[i] * MAXHIST / maxvalue) <= 0)
                len = 0;
        }
        else
        {
            len = 0;
        }
        while (len > 0)
        {
            putchar('#');
            --len;
        }
        putchar('\n');
    }

    if (overflow > 0)
        printf("There are %d words > %d\n", overflow, MAXWORD);
}