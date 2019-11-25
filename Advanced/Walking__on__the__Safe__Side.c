#include <stdio.h>
#include <string.h>
#define MAXN 100
int main(void)
{
	int n, m, i, j;
	unsigned char map[MAXN][MAXN];
	int walk[MAXN][MAXN];
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(map, 0, sizeof(map));
		memset(walk, 0, sizeof(walk));
		walk[0][0] = 1LL;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%hhu", &map[i][j]);
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (map[i][j] == 1)
				{
					walk[i][j] = 0;
				}
				else if (i == 0)
				{
					if (j == 0)
					{
						continue;
					}
					walk[i][j] = walk[i][j - 1] % 10000;
				}
				else if (j == 0)
				{
					if (i == 0)
					{
						continue;
					}
					walk[i][j] = walk[i - 1][j] % 10000;
				}
				else
				{
					walk[i][j] = (walk[i - 1][j] % 10000 + walk[i][j - 1] % 10000) % 10000;
				}
			}
		}
		printf("%d\n", walk[n - 1][m - 1]);
	}
}