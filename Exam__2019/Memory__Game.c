#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int i, card[101], now;
	for (i = 0; i < 101; i++)
	{
		card[i] = -1;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &now);
		if (card[now] == -1)
		{
			card[now] = i;
			printf("%d\n", i);
		}
		else
		{
			printf("%d %d %d\n", i, card[now], now);
			card[now] = -1;
		}
	}
	return 0;
}