#include <stdio.h>
#define MAX_N 101
long long club[MAX_N] = {0LL};
int ans[MAX_N] = {0};
int N, K;
int find(int now, long long common, int count)
{
	if (count == 0)
	{
		return 1;
	}
	int i;
	for (i = now; i < N && N - i >= count; i++)
	{
		if ((common & club[i])==0LL)
		{
			if (find(i + 1, common | club[i], count - 1))
			{
				ans[i] = 1;
				return 1;
			}
		}
	}
	return 0;
}
int main(void)
{
	int i, j, n, m;
	scanf("%d%d", &N, &K);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &n);
		for (j = 0; j < n&&scanf("%d",&m)!=EOF; j++)
		{
			club[i] |= (1LL << m);
		}
	}
	if (find(0, 0LL, K))
	{
		for (i = 0; i < N; i++)
		{
			if (ans[i])
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}