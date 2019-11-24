#include <stdio.h>
#include <stdlib.h>
char map[1024][1024] = {};
int position[1024][2] = {};
int main(void)
{
	int q, command;
	int n, m, i, j;
	int headx, heady, tailx, taily;
	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d", &headx, &heady, &tailx, &taily);
	scanf("%d", &q);
	int len = abs(headx - tailx) + abs(heady - taily) + 1;
	int headid = 0, tailid = len - 1, now = 0, tmpx, tmpy, tmptmpx, tmptmpy;
	int dx = headx < tailx ? 1 : (headx > tailx ? -1 : 0);
	int dy = heady < taily ? 1 : (heady > taily ? -1 : 0);
	for (i = 0; i < len; i++)
	{
		map[headx][heady] = 1;
		position[i][0] = headx;
		position[i][1] = heady;
		headx += dx;
		heady += dy;
	}
	const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	while (q--)
	{
		scanf("%d", &command);
		tmpx = position[tailid][0];
		tmpy = position[tailid][1];
		map[tmpx][tmpy] = 0;
		tailid--;
		if (tailid < 0)
		{
			tailid = len - 1;
		}
		tmptmpx = tmpx;
		tmptmpy = tmpy;
		tmpx = position[headid][0];
		tmpy = position[headid][1];
		tmpx += directions[command][0];
		tmpy += directions[command][1];
		if (tmpx < 0 || tmpy < 0 || tmpx >= n || tmpy >= m || map[tmpx][tmpy])
		{
			map[tmptmpx][tmptmpy] = 1;
			break;
		}
		headid--;
		if (headid < 0)
		{
			headid = len - 1;
		}
		position[headid][0] = tmpx;
		position[headid][1] = tmpy;
		map[tmpx][tmpy] = 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			putchar(map[i][j] + '0');
		}
		puts("");
	}
	return 0;
}