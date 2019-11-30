#include <stdio.h>
#define MAX_N 14
static int distances[MAX_N][MAX_N], walked[MAX_N], n, ans = 2147483647;
void travel(int distance, int now, int count)
{
	if (distance >= ans)
	{
		return;
	}
	if (count == n)
	{
		distance += distances[now][0];
		if (distance < ans)
		{
			ans = distance;
		}
		return;
	}
	int i;
	for (i = 1; i < n; i++)
	{
		if (i == now)
		{
			continue;
		}
		if (walked[i])
		{
			continue;
		}
		else
		{
			walked[i] = 1;
			travel(distance + distances[now][i], i, count + 1);
			walked[i] = 0;
		}
	}
}
int main(void)
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &distances[i][j]);
		}
	}
	travel(0, 0, 1);
	printf("%d\n", ans);
	return 0;
}