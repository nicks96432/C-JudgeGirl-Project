#include <stdio.h>
#define MAX_N 1000
int square[MAX_N][MAX_N] = {};
int main(void)
{
	int i, j, n, column, row, number, count = 0;
	scanf("%d%d%d%d", &n, &number, &row, &column);
	const int n__square = n * n;
	while (count < n__square)
	{
		number %= (n__square + 1);
		if (number == 0)
		{
			number = 1;
		}
		square[row][column] = number;
		number++;
		count++;
		if (number % n == 1 && number > 1)
		{
			row++;
		}
		else
		{
			row--;
			column++;
		}
		if (column >= n)
		{
			column = 0;
		}
		if (row < 0)
		{
			row = n - 1;
		}
		else if (row >= n)
		{
			row = 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			printf("%d ", square[i][j]);
		}
		printf("%d\n", square[i][j]);
	}
	return 0;
}