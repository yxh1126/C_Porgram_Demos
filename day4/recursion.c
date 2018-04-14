#include <stdio.h>

int adder_interation(int);
int adder_recursion(int);

float factorial_recursion(float);
float factorial_interation(float);

int main(int argc, char const *argv[])
{
	int res1 = adder_interation(10);
	int res2 = adder_recursion(10);

	float res3 = factorial_interation(20);
	float res4 = factorial_recursion(20);

	printf("SUM: Inter: %d; Rec: %d\n", res1, res2);
	printf("MULT: Inter: %f; Rec: %f\n", res3, res4);

	return 0;
}

int adder_interation(int count)
{
	int sum = 0;
	int i = 0;
	for (i = 1; i <= count; ++i)
	{
		sum += i;
	}

	return sum;
}

int adder_recursion(int count)
{
	if (count == 1)
	{
		return 1;
	}

	return adder_recursion(count - 1) + count;
}

float factorial_interation(float count)
{
	float res = 1;
	float i = 0;
	for (i = 1; i <= count; ++i)
	{
		res *= i;
	}

	return res;
}

float factorial_recursion(float count)
{
	if (count == 1)
	{
		return count;
	}
	else
	{
		return factorial_recursion(count - 1) * count;
	}
}
