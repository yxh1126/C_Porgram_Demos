#include <stdio.h>
#include "stdlib.h"

int file_total_line(const char* fileName);
int* file_to_num_array(const char* fileName, int arr_size);

void swap(int *xp, int *yp);
void bubble_sort(int arr[], int n);

int main(int argc, const char* argv[])
{
    if (argc > 1)
    {
        const char* fileName = argv[1];

        int arr_size = file_total_line(fileName);

        int* ptr = 0;
        ptr = file_to_num_array(fileName, arr_size);

        // printf("%d\n", arr_size);

        bubble_sort(ptr, arr_size);

        int idx = 0;
        for (idx = 0; idx < arr_size; idx++)
        {
            printf("%d\n", ptr[idx]);
        }

        free(ptr);
    }
    else
    {
        printf("Enter a file name!\n");
    }

    return 0;
}

int file_total_line(const char* fileName)
{
    FILE* file = fopen(fileName, "r");

    char line[256];
    int arr_size = 0;

    while (fgets(line, sizeof(line), file))
    {
        arr_size++;
    }

    fclose(file);

    return arr_size;
}

int* file_to_num_array(const char* fileName, int arr_size)
{
    FILE* file = fopen(fileName, "r");

    char line[256];
    int* num_array = 0;
    num_array = (int*) malloc(arr_size * sizeof(int));

    int idx = 0;

    while (fgets(line, sizeof(line), file))
    {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        int val = atoi(line);
        *(num_array + idx) = val;
        idx++;
    }

    fclose(file);

    return num_array;
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
