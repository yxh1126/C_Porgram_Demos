#include <stdio.h>
#include <stdlib.h>

int find_array_max(int* arr, int size);
void linear_sort(int*arr, int size);

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		int input_var[argc-1];

		int i;
		for (i = 1; i < argc; ++i)
		{
			input_var[i-1] = atoi(argv[i]);
		}

		linear_sort(input_var, argc-1);
	}
	else
	{
		printf("Input some value!\n");
	}

	return 0;
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