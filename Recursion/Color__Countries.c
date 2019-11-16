#include <stdio.h>
#include <string.h>
#define MAX_N 400
int adjacent[MAX_N][2], order[MAX_N];
int n, c, p;
int color(int);
int main(void)
{
	int i, yes;
	memset(adjacent, 0, sizeof(adjacent));
	memset(order, 0, sizeof(order));
	scanf("%d%d%d", &n, &c, &p);
	for (i = 0; i < p; i++)
	{
		scanf("%d%d", &adjacent[i][0], &adjacent[i][1]);
	}
	yes = color(0);
	if (!yes)
	{
		printf("no solution.\n");
	}
	return 0;
}
int color(int index)
{
	int i;
	/* 檢查 */
	for (i = 0; i < p; i++)
	{
		if (order[adjacent[i][0]] == order[adjacent[i][1]] && order[adjacent[i][0]] != 0)
		{
			return 0;
		}
	}
	/* 成功 */
	if (index == n)
	{
		for (i = 0; i < n; i++)
		{
			printf("%d\n", order[i]);
		}
		return 1;
	}
	/* 填顏色 */
	for (i = 1; i <= c; i++)
	{
		order[index] = i;
		if (color(index + 1))
		{
			return 1;
		}
	}
	order[index] = 0;
	return 0;
}