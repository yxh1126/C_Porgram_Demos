#include <stdio.h>
#include "stdlib.h"

int file_total_line(const char* fileName);
int* file_to_num_array(const char* fileName, int arr_size);

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main(int argc, const char* argv[])
{
    if (argc > 1)
    {
        const char* fileName = argv[1];

        int arr_size = file_total_line(fileName);

        int* ptr = 0;
        ptr = file_to_num_array(fileName, arr_size);

        // printf("%d\n", arr_size);

        mergeSort(ptr, 0, arr_size-1);

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


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
