#include <stdio.h>
#define MAX_N 64
static int n;
static int maxdonation = -1;
static int moneys[MAX_N] = {};
static int relationship[MAX_N][MAX_N] = {};
static int used[MAX_N] = {};
static void donate(int now, int money)
{
	int i;
	if (now == n)
	{
		if (money > maxdonation)
		{
			maxdonation = money;
		}
		return;
	}
	donate(now + 1, money);
	for (i = 0; i < now; i++)
	{
		if (used[i] && relationship[i][now] == 1)
		{
			return;
		}
	}
	used[now] = 1;
	donate(now + 1, money + moneys[now]);
	used[now] = 0;
}
int main(void)
{
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &moneys[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &relationship[i][j]);
		}
	}
	donate(0, 0);
	printf("%d\n", maxdonation);
	return 0;
}