#include <stdio.h>
#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0
#define LOWER_SENTINEL -1

int main()
{
    int c, hist_index, state, i, j, overflow;
    int hist[MAXWORD];
    int maxvalue;

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
    for (i = MAXHIST; i > 0; --i)
    {
        for (j = 0; j < MAXWORD; ++j)
        {
            if (hist[j] * MAXHIST / maxvalue >= i)
                printf("   # ");
            else
                printf("     ");
        }
        putchar('\n');
    }

    /* Draw the labels */
    for (i = 1; i <= MAXWORD; ++i)
        printf("%4d ", i);
    putchar('\n');

    for (i = 0; i < MAXWORD; ++i)
        printf("%4d ", hist[i]);
    putchar('\n');

    if (overflow > 0)
        printf("There are %d words > %d\n", overflow, MAXWORD);
}