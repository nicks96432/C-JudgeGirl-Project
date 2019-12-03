#include <stdio.h>
#include <string.h>
#define MAX_N 8
static int map[MAX_N][MAX_N] = {}, ans[MAX_N] = {}, tmpans[MAX_N] = {}, used[MAX_N] = {1, 0};
static int n;
static int max = 0;
static void findroad(int now, int count)
{
	if (now == 0 && used[0] == 2)
	{
		if (count > max)
		{
			max = count;
			memmove(ans, tmpans, sizeof(tmpans));
		}
	}
	int i;
	for (i = 0; i < n; i++)
	{
		if (map[now][i] == 0)
		{
			continue;
		}
		if (used[i] == 1 && i != 0)
		{
			continue;
		}
		used[i]++;
		tmpans[count] = i;
		findroad(i, count + 1);
		used[i]--;
		tmpans[count] = 0;
	}
	return;
}
int main(void)
{
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	findroad(0, 0);
	for (i = 0; i < max - 1; i++)
	{
		printf("%d%c", ans[i], i == max - 1 ? '\n' : ' ');
	}
	return 0;
}