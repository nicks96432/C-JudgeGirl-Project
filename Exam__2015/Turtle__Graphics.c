#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool check(int, int, int, int);
int main(void)
{
	int line, x, y;
	scanf("%d%d%d", &line, &x, &y);
	bool grid[x][y];
	memset(grid, 0, sizeof(bool) * x * y);
	int i, j, k, l, n, prev__x, prev__y, point__x, point__y;
	for (i = 1; i <= line; i++)
	{
		scanf("%d", &n);
		scanf("%d%d", &prev__x, &prev__y);
		if (prev__x > x || prev__y > y)
		{
			printf("ERROR %d 1", i);
			return 0;
		}
		for (j = 2; j <= n; j++)
		{
			scanf("%d%d", &point__x, &point__y);
			if (check(point__x, point__y, prev__x, prev__y) == false)
			{
				printf("ERROR %d %d", i, j);
				return 0;
			}
			else
			{
				if (point__x == prev__x)
				{
					if (point__y > prev__y)
					{
						for (k = prev__y; k <= point__y; k++)
						{
							grid[k][point__x] = true;
						}
					}
					else
					{
						for (k = point__y; k <= prev__y; k++)
						{
							grid[k][point__x] = true;
						}
					}
				}
				else if (point__y == prev__y)
				{
					if (point__x > prev__x)
					{
						for (k = prev__x; k <= point__x; k++)
						{
							grid[point__y][k] = true;
						}
					}
					else
					{
						for (k = point__x; k <= prev__x; k++)
						{
							grid[point__y][k] = true;
						}
					}
				}
				else if (point__x - prev__x == point__y - prev__y)
				{
					if (point__x > prev__x)
					{
						for (k = prev__x, l = prev__y; k <= point__x; k++, l++)
						{
							grid[l][k] = true;
						}
					}
					else
					{
						for (k = point__x, l = point__y; k <= prev__x; k++, l++)
						{
							grid[l][k] = true;
						}
					}
				}
				else if (point__x - prev__x == prev__y - point__y)
				{
					if (point__x > prev__x)
					{
						for (k = prev__x, l = prev__y; k <= point__x; k++, l--)
						{
							grid[l][k] = true;
						}
					}
					else
					{
						for (k = point__x, l = point__y; k <= prev__x; k++, l--)
						{
							grid[l][k] = true;
						}
					}
				}
			}
			prev__x = point__x;
			prev__y = point__y;
		}
	}
	for (i = x - 1; i >= 0; i--)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}
bool check(int point__x, int point__y, int prev__x, int prev__y)
{
	if (point__x == prev__x || point__y == prev__y || point__x - prev__x == point__y - prev__y || point__x - prev__x == prev__y - point__y)
	{
		return true;
	}
	else
	{
		return false;
	}
}