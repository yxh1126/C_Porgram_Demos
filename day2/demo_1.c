#include "stdio.h"
#include "stdlib.h"

void swap(int *xp, int *yp);
void bubble_sort(int arr[], int n);

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        int total = 0;
        int i = 0;
        int unsort_arr[argc-1];

        for (i = 1; i < argc; ++i)
        {
            int val = atoi(argv[i]);
            printf("List the input value: %d\n", val);

            unsort_arr[i-1] = val;

            total = total + val;
        }
        printf("The sum of all the input is: %d\n", total);

        bubble_sort(unsort_arr, argc-1);

        printf("The sorted arrary is: ");
        int j = 0;
        for (j = 0; j < argc-1; ++j)
        {
            printf("%d ", unsort_arr[j]);
        }
        printf("\n");
    }
    else
    {
        printf("Ops, You don't type in any value...\n");
    }

    return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int arr[], int n)
{
   int i = 0;
   int j = 0;

   for (i = 0; i < n-1; i++)
   {
    for (j = 0; j < n-i-1; j++)
    {
        if (arr[j] > arr[j+1])
        {
            swap(&arr[j], &arr[j+1]);
        }
    }
   }
}