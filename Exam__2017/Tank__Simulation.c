#include <stdio.h>
#define MAX_M 500
int main(void)
{
	int map[MAX_M][MAX_M] = {};
	int n, m, l, w;
	scanf("%d%d%d%d", &n, &m, &l, &w);
	int o;
	int i, j;
	int x, y;
	scanf("%d", &o);
	for (i = 0; i < o; i++)
	{
		scanf("%d%d", &x, &y);
		map[y][x] = 2;
	}
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < w; j++)
		{
			map[i][j] = 1;
		}
	}
	int instruction, count;
	x = 0;
	y = 0;
	while (scanf("%d", &instruction) != EOF)
	{
		count = 0;
		switch (instruction)
		{
		case 0:
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					printf("%d", map[i][j]);
				}
				printf("\n");
			}
			break;
		case 1:
			if (x + w < m)
			{
				for (i = 0; i < l; i++)
				{
					if (map[y + i][x + w] == 2)
					{
						count++;
					}
				}
				if (count < 2)
				{
					for (i = 0; i < l; i++)
					{
						map[y + i][x + w] = 1;
						map[y + i][x] = 0;
					}
					x++;
				}
			}
			break;
		case 2:
			if (y + l < n)
			{
				for (i = 0; i < w; i++)
				{
					if (map[y + l][x + i] == 2)
					{
						count++;
					}
				}
				if (count < 2)
				{
					for (i = 0; i < w; i++)
					{
						map[y + l][x + i] = 1;
						map[y][x + i] = 0;
					}
					y++;
				}
			}
			break;
		case 3:
			if (x >= 1)
			{
				for (i = 0; i < l; i++)
				{
					if (map[y + i][x - 1] == 2)
					{
						count++;
					}
				}
				if (count < 2)
				{
					for (i = 0; i < l; i++)
					{
						map[y + i][x - 1] = 1;
						map[y + i][x + w - 1] = 0;
					}
					x--;
				}
			}
			break;
		case 4:
			if (y >= 1)
			{
				for (i = 0; i < w; i++)
				{
					if (map[y - 1][x + i] == 2)
					{
						count++;
					}
				}
				if (count < 2)
				{
					for (i = 0; i < w; i++)
					{
						map[y - 1][x + i] = 1;
						map[y + l - 1][x + i] = 0;
					}
					y--;
				}
			}
			break;
		case 5:
			if (x + w < m && y + l < n)
			{
				for (i = 0; i < l-1; i++)
				{
					if (map[y + i + 1][x + w] == 2)
					{
						count++;
					}
				}
				for (i = 0; i < w - 1; i++)
				{
					if (map[y + l][x + i + 1] == 2)
					{
						count++;
					}
				}
				if (count < 2)
				{
					for (i = 0; i < w; i++)
					{
						map[y + l][x + i + 1] = 1;
						map[y][x + i] = 0;
					}
					for (i = 0; i < l; i++)
					{
						map[y + i + 1][x + w] = 1;
						map[y + i][x] = 0;
					}
					x++;
					y++;
				}
			}
			break;
		}
	}
	return 0;
}