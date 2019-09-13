#include <stdio.h>
int main(void)
{
	int a[102][102], neighbor[10000], r, c, i, j, k = 0;
	scanf("%d %d", &r, &c);
	for (i = 0; i < 102; i++)
	{
		for (j = 0; j < 102; j++)
		{
			a[i][j] = -1;
		}
	}
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j + 1])
			{
				neighbor[k] = a[i][j];
				k++;
			}
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d\n", neighbor[i]);
	}
	return 0;
}