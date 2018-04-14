# include <stdio.h>
# include <stdlib.h>
void bubble_sort (int number[], int size);



/*void bubble_sort (int number[], int size)
{
	int i;
	int m;
	int n;
	int temp;
	for (int m = 0; m < size; m++)
	{
		printf("The array is:");
		for (int n = m+1; n < size; n++)
		{
			if number[m] > number[n]
			{
				temp = number[m]; 
				number[m]=number[n];
				number[n] = temp;
			}
		}
		for (int i = 0; i < size; i++)
		{
			printf("%d ",number[n]);
		}
	printf("\n");
	}
		
}*/
int main(int argc, char const *argv[])
{
	

	int i;
	int a = 0;
	int s = 0;
	int number[argc-1];
	for (i = 0; i < argc-1; i++)
	 {
	 	number[i] = atoi(argv[i+1]);
	 	a = number[i];
	 	s = s + a;
	 	printf("The %d number is %d\n", i+1, number[i]);
	 } 
	 printf("%d\n", s);
	 bubble_sort (number, argc-1);


}
void bubble_sort (int number[], int size)

{
	int m;
	int n;
	for (m = 0; m < size-1; m++)
	{
		for (n = 0; n < size-1; n++)
		{
			if (number[n] > number[n+1])
			{
				int temp;
				temp = number[n];
				number[n] = number[n+1];
				number[n+1] = temp;

			}
		}
	}

	int i;
	printf("The array is: " );
	for (i = 0; i < size; i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n");
} 