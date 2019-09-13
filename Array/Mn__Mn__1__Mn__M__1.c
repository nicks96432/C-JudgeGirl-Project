#include <stdio.h>
int main(void)
{
	int i, n, m;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	int remainder[m];
	for (i = 0; i < m; i++)
	{
		remainder[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		remainder[a[i] % m]++;
	}
	for (i = 0; i < m; i++)
	{
		printf("%d\n", remainder[i]);
	}
	return 0;
}