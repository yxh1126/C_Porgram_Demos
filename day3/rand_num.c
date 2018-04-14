#include <time.h>
#include <stdlib.h>
#include "stdio.h"

#define NUM_RANGE 1000000

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        srand(time(NULL));   // should only be called once

        int counts = atoi(argv[1]);
        int i = 0;
        for (i = 0; i < counts; ++i)
        {
            int r = rand() % NUM_RANGE;      // returns a pseudo-random integer between 0 and RAND_MAX
            printf("%d\n", r);
        }
    }
    else
    {
        printf("Tell me how many numbers you want to generate!\n");
    }

    return 0;
}