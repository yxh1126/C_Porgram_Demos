#include <stdio.h>
#include <stdlib.h>

double fibonacci(double);
double fibonacci_memo(double);

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		int key = atoi(argv[1]);

		int i = 0;
		for (i = 0; i <= key; ++i)
		{
			double fibo1 = fibonacci_memo(i);
			double fibo2 = fibonacci_memo(i);

			printf("Index: %d --> Fibo1: %f; Fibo2: %f\n", i, fibo1, fibo2);
		}
	}
	else
	{
		printf("A number is required!\n");
	}

	return 0;
}

double fibonacci(double n)
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

double fibonacci_memo(double n)
{
	if (n <= 1)
	{
		return n;
	}

	int size = (int)n;
	double memo[size+1];
	
	memo[0] = 0;
	memo[1] = 1;

	int i = 0;
	for (i = 2; i <= size; ++i)
	{
		memo[i] = memo[i-1] + memo[i-2];
	}

	return memo[size];
}
