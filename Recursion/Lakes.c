#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 402
#define MAX_LAKES 80001
int n, m;
int map[MAX_LEN][MAX_LEN];
int lakes[MAX_LAKES];
int comp(const void *x, const void *y)
{
	return *(int *)y - *(int *)x;
}
int lake(int i, int j)
{
	if (i < 0 || j < 0 || i >= n || j >= m || map[i][j] != 1)
	{
		return 0;
	}
	map[i][j] = -1; /* 走過了 */
	return 1 + lake(i + 1, j) + lake(i, j + 1) + lake(i - 1, j) + lake(i, j - 1);
}
int main(void)
{
	scanf("%d%d", &n, &m);
	int i, j, count;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	count = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (map[i][j] > 0)
			{
				lakes[count] = lake(i, j);
				count++;
			}
		}
	}
	qsort(lakes, count, sizeof(lakes[0]), comp);
	for (i = 0; i < count; i++)
	{
		printf("%d\n", lakes[i]);
	}
	return 0;
}
