#include <stdio.h>
#include <string.h>
#define MAX_N 1024
#define MAX_M 512
int main(void)
{
	int n, m;
	int i, j, k, l, ans;
	unsigned long long things[MAX_N][MAX_M / 64];
	unsigned long long up, down;
	int count1, count2;
	char thing[MAX_M];
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(things, 0, sizeof(things));
		for (i = 0; i < n; i++)
		{
			scanf("%s", thing);
			for (j = 0; j < m; j++)
			{
				if (thing[j] == '1')
				{
					things[i][j >> 6] |= (1ULL << (63 - (j & 63)));
				}
			}
		}
		ans = 0;
		for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				count1 = 0;
				count2 = 0;
				for (k = 0; k < m / 64 + ((m % 64 == 0) ? 0 : 1); k++)
				{
					up = things[i][k] & things[j][k];
					down = things[i][k] | things[j][k];
					for (l = 0; l < 64; l++)
					{
						count1 += (up & (1ULL << l)) > 0 ? 1 : 0;
						count2 += (down & (1ULL << l)) > 0 ? 1 : 0;
					}
				}
				if (5 * count1 >= 4 * count2)
				{
					ans++;
				}
			}
		}
		printf("%.2lf\n", (double)ans * 100.F / (n * (n - 1) / 2));
	}
	return 0;
}