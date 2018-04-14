#include <stdio.h>

int main(int argc, char const *argv[])
{
	int board[3][3];

	int row, col;
	for (row = 0; row < 3; ++row)
	{
		for (col = 0; col < 3; ++col)
		{
			board[row][col] = 0;
		}
	}

	while(1)
	{
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);

		board[x-1][y-1] = 1;

		for (row = 0; row < 3; ++row)
		{
			for (col = 0; col < 3; ++col)
			{
				if (board[row][col] != 0)
				{
					printf(" X ");
				}
				else
				{
					printf("   ");
				}


				if (col != 2)
				{
					printf("|");
				}
				

				// printf("%d ", board[row][col]);
			}

			if (row != 2)
			{
				printf("\n");
				printf("-----------\n");
			}
		}

		int flag = 1;

		for (row = 0; row < 3; ++row)
		{
			for (col = 0; col < 3; ++col)
			{
				if (board[row][col] == 0)
				{
					flag = 0;
				}
				
			}
		}
		printf("\n");

		if (flag == 1)
		{
			break;
		}
		
	}

	printf("\n");
	return 0;
}
