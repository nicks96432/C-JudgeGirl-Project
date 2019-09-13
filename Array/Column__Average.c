#include <stdio.h>
int main(void)
{
	int i, j, r, c, a[100][100];
	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++)
	{
		a[r][i] = 0;
		for (j = 0; j < c; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			a[r][j] += a[i][j];
		}
	}
	for (j = 0; j < c; j++)
	{
		printf("%d\n", a[r][j] / r);
	}
	return 0;
}