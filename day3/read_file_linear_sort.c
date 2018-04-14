#include <stdio.h>
#include "stdlib.h"

int file_total_line(const char* fileName);
int* file_to_num_array(const char* fileName, int arr_size);

int find_array_max(int* arr, int size);
void linear_sort(int*arr, int size);

int main(int argc, const char* argv[])
{
    if (argc > 1)
    {
        const char* fileName = argv[1];

        int arr_size = file_total_line(fileName);

        int* ptr = 0;
        ptr = file_to_num_array(fileName, arr_size);

        // printf("%d\n", arr_size);

        linear_sort(ptr, arr_size);

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


void linear_sort(int* arr, int size)
{
    int max_idx = find_array_max(arr, size) + 1;

    int* num_array = 0;
    num_array = (int*) malloc(max_idx * sizeof(int));

    int i;
    for (i = 0; i < size; ++i)
    {
        ++num_array[arr[i]];
    }

    for (i = 0; i < max_idx; ++i)
    {
        int check_var = num_array[i];
        if (check_var > 0)
        {
            int j;
            for (j = 0; j < check_var; ++j)
            {
                printf("%d\n", i);
            }
        }
    }

}

int find_array_max(int* arr, int size)
{
    int max_var = -1;

    int i;
    for (i = 0; i < size; ++i)
    {
        int one_var = arr[i];

        if (one_var > max_var)
        {
            max_var = one_var;
        }
    }

    return max_var;
}
