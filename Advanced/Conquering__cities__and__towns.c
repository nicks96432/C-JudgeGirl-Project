#include <stdio.h>
#include <string.h>
#define MAX_N 1024
int main(void)
{
	int i, j, n, m, q;
	int lx, ly, rx, ry, count;
	_Bool found = 0;
	static int map[MAX_N][MAX_N];
	memset(map, 1, sizeof(map));
	scanf("%d%d%d", &n, &m, &q);
	while (q--)
	{
		scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
		count = 0;
		for (i = lx; i <= rx; i++)
		{
			for (j = ly; j <= ry; j++)
			{
				if (map[i][j])
				{
					count++;
				}
			}
		}
		printf("%d", count);
		if (count == 0)
		{
			puts("");
			continue;
		}
		for (i = lx; i <= rx; i++)
		{
			for (j = ly; j <= ry; j++)
			{
				if (map[i][j])
				{
					map[i][j] = 0;
					printf(" (%d, %d)", i, j);
				}
			}
		}
		puts("");
	}
}