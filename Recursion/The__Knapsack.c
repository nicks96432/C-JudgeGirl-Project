#include <stdio.h>
typedef struct Thing
{
	int weight;
	int value;
} thing;
int n, ans = 0;
int W;
thing things[15];
void knapsack(int, int, int);
int main(void)
{
	scanf("%d%d", &n, &W);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &things[i].weight, &things[i].value);
	}
	knapsack(0, 0, 0);
	printf("%d ", ans);
	return 0;
}
void knapsack(int w, int value, int now)
{
	if (w > W)
	{
		return;
	}
	ans = value > ans ? value : ans;
	if (now == n)
	{
		return;
	}
	knapsack(w + things[now].weight, value + things[now].value, now + 1);
	knapsack(w, value, now + 1);
}