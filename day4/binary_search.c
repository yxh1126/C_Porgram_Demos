typedef enum
{
	FALSE,
	TRUE
} BOOLEAN;


#include <stdio.h>
#include <stdlib.h>

BOOLEAN binary_searh(int* arr, int size, int key);
BOOLEAN binary_searh_rec(int* arr, int key, int left, int right);

int main(int argc, char const *argv[])
{
	if (argc > 2)
	{
		int key = atoi(argv[argc-1]);
		int inputs[argc-2];

		int i;
		for (i = 1; i < argc-1; ++i)
		{
			inputs[i-1] = atoi(argv[i]);
		}

		BOOLEAN res1 = binary_searh(inputs, argc-2, key);
		BOOLEAN res2 = binary_searh_rec(inputs, key, 0, argc-3);

		char* out1 = 0;
		char* out2 = 0;

		if (res1)
		{
			out1 = "IN";
		}
		else
		{
			out1 = "NOT IN";
		}

		if (res2)
		{
			out2 = "IN";
		}
		else
		{
			out2 = "NOT IN";
		}

		printf("The value %d is %s the array - interation.\n", key, out1);
		printf("The value %d is %s the array - recursion.\n", key, out2);
	}
	else
	{
		printf("Input at least 2 values.\n");
	}

	return 0;
}

BOOLEAN binary_searh(int* arr, int size, int key)
{
	int left = 0;
	int right = size - 1;

	while(left <= right)
	{
		int middle = (left + right) / 2;

		if (key == arr[middle])
		{
			return TRUE;
		}
		else if (key < arr[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}

	return FALSE;
}

BOOLEAN binary_searh_rec(int* arr, int key, int left, int right)
{
	if (left > right)
	{
		return FALSE;
	}
	
	int middle = (left + right) / 2;

	if (key == arr[middle])
	{
		return TRUE;
	}
	else if (key < arr[middle])
	{
		return binary_searh_rec(arr, key, left, middle-1);
	}
	else
	{
		return binary_searh_rec(arr, key, middle+1, right);
	}
}
