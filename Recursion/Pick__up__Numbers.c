#include <stdio.h>
#include <stdbool.h>
#define MAX_NUMBERS 21
int numbers[MAX_NUMBERS];
int k, n, m;
int pick(int, int, int);
int main(void)
{
	scanf("%d%d%d", &k, &n, &m);
	int i,ans;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &numbers[i]);
	}
	ans = pick(0, 0, 0);
	printf("%d", ans);
}
int pick(int index, int count, int total)
{
	if (index == n)
	{
		return total <= m && count >= k;
	}
	return pick(index + 1, count, total) + pick(index + 1, count + 1, total + numbers[index]);
}