#include <stdio.h>
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i, num[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", num + i);
	}
	int sum[m], max[m], min[m], tmp;
	for (i = 0; i < m; i++)
	{
		sum[i] = 0;
		max[i] = 0;
		min[i] = 2147483647;
	}
	for (i = 0; i < n; i++)
	{
		tmp = num[i] % m;
		sum[tmp] += num[i];
		if (num[i] > max[tmp])
		{
			max[tmp] = num[i];
		}
		if (num[i] < min[tmp])
		{
			min[tmp] = num[i];
		}
	}
	for (i = 0; i < m; i++)
	{
		printf("%d %d %d\n", sum[i], max[i], min[i]);
	}
	return 0;
}