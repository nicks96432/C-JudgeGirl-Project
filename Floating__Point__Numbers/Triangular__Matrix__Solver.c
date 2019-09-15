#include <stdio.h>
int main(void)
{
	int i, j, n;
	scanf("%d", &n);
	double a[n][n], x[n], y[n], tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &y[i]);
	}
	for (i = 0; i < n; i++)
	{
		x[i] = 0;
	}
	x[n - 1] = y[n - 1] / a[n - 1][n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		tmp = 0;
		for (j = n - 1; j >= i; j--)
		{
			tmp += x[j] * a[i][j];
		}
		x[i] = (y[i] - tmp) / a[i][i];
	}
	for (i = 0; i < n; i++)
	{
		printf("%lf\n", x[i]);
	}
	return 0;
}