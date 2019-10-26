#include <stdio.h>
#define MAXN 1000
int array[MAXN][MAXN] = {};
int main(void)
{
	int N;
	scanf("%d", &N);
	int i, j, ans = 0;
	int row = 0, column = 0, diagonal__down = 0, diagonal__up = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	for (i = 0; i < N; i++)
	{
		row = 0;
		for (j = 0; j < N; j++)
		{
			if (array[i][j] == 1)
			{
				row++;
				if (row > ans)
				{
					ans = row;
				}
			}
			else
			{
				row = 0;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		column = 0;
		for (j = 0; j < N; j++)
		{
			if (array[j][i] == 1)
			{
				column++;
				if (column > ans)
				{
					ans = column;
				}
			}
			else
			{
				column = 0;
			}
		}
	}
	for (i = 1; i < N; i++)
	{
		diagonal__down = 0;
		for (j = 0; j < N - i; j++)
		{
			if (array[i + j][j] == 1)
			{
				diagonal__down++;
				if (diagonal__down > ans)
				{
					ans = diagonal__down;
				}
			}
			else
			{
				diagonal__down = 0;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		diagonal__up = 0;
		for (j = 0; j < N - i; j++)
		{
			if (array[j][i + j] == 1)
			{
				diagonal__up++;
				if (diagonal__up > ans)
				{
					ans = diagonal__up;
				}
			}
			else
			{
				diagonal__up = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}