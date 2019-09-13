#include <stdio.h>
int main(void)
{
	int i, j, n, a[102][102], connection, intersection = 0, T__junction = 0, turn = 0, dead__end = 0;
	scanf("%d", &n);
	for (i = 0; i < 102; i++)
	{
		for (j = 0; j < 102; j++)
		{
			a[i][j] = -1;
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			connection = 0;
			if (a[i][j] == 1)
			{
				if (a[i][j - 1] == 1)
				{
					connection++;
				}
				if (a[i][j + 1] == 1)
				{
					connection++;
				}
				if (a[i - 1][j] == 1)
				{
					connection++;
				}
				if (a[i + 1][j] == 1)
				{
					connection++;
				}
				if (connection == 4)
				{
					intersection++;
				}
				else if (connection == 3)
				{
					T__junction++;
				}
				else if (connection == 2)
				{
					if ((a[i + 1][j] == 1 && a[i - 1][j] == 1) || (a[i][j + 1] == 1 && a[i][j - 1] == 1))
					{
						continue;
					}
					else
					{
						turn++;
					}
				}
				else if (connection == 1)
				{
					dead__end++;
				}
			}
		}
	}
	printf("%d\n%d\n%d\n%d", intersection, T__junction, turn, dead__end);
	return 0;
}