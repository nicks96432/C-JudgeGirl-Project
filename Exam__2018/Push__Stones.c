#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int row, column, energy;
	scanf("%d%d%d", &row, &column, &energy);
	int o;
	scanf("%d", &o);
	int i, stone[o][3];
	bool can__push;
	for (i = 0; i < o; i++)
	{
		scanf("%d%d%d", &stone[i][0], &stone[i][1], &stone[i][2]);
	}
	int j, map[n][m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			map[i][j] = 0;
		}
	}
	map[row][column] = energy;
	for (i = 0; i < o; i++)
	{
		map[stone[i][0]][stone[i][1]] = stone[i][2];
	}
	int command, count;
	while (scanf("%d", &command) != EOF)
	{
		count = 0;
		can__push = false;
		switch (command)
		{
		case 0: //不動
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m - 1; j++)
				{
					printf("%d ", map[i][j]);
				}
				printf("%d\n", map[i][j]);
			}
			break;
		case 1: //向右
			if (column < m - 1)
			{
				for (i = column + 1; i < m; i++)
				{
					count += map[row][i];
					if (map[row][i] == 0)
					{
						can__push = true;
						break;
					}
				}
				if (!can__push)
				{
					continue;
				}
				if (i > m - 1)
				{
					i = m - 1;
				}
				if (energy > count)
				{
					energy -= count;
					for (; i > column; i--)
					{
						map[row][i] = map[row][i - 1];
					}
					map[row][i] = 0;
					column++;
				}
			}
			break;
		case 2: //向下
			if (row <= n - 2)
			{
				for (i = row + 1; i < n; i++)
				{
					count += map[i][column];
					if (map[i][column] == 0)
					{
						can__push = true;
						break;
					}
				}
				if (!can__push)
				{
					continue;
				}
				if (i > n - 1)
				{
					i = n - 1;
				}
				if (energy > count)
				{
					energy -= count;
					for (; i > row; i--)
					{
						map[i][column] = map[i - 1][column];
					}
					map[i][column] = 0;
					row++;
				}
			}
			break;
		case 3: //向左
			if (column > 0)
			{
				for (i = column - 1; i >= 0; i--)
				{
					count += map[row][i];
					if (map[row][i] == 0)
					{
						can__push = true;
						break;
					}
				}
				if (!can__push)
				{
					continue;
				}
				if (i < 0)
				{
					i = 0;
				}
				if (energy > count)
				{
					energy -= count;
					for (; i < column; i++)
					{
						map[row][i] = map[row][i + 1];
					}
					map[row][i] = 0;
					column--;
				}
			}
			break;
		case 4: //向上
			if (row > 0)
			{
				for (i = row - 1; i >= 0; i--)
				{
					count += map[i][column];
					if (map[i][column] == 0)
					{
						can__push = true;
						break;
					}
				}
				if (!can__push)
				{
					continue;
				}
				if (i < 0)
				{
					i = 0;
				}
				if (energy > count)
				{
					energy -= count;
					for (; i < row; i++)
					{
						map[i][column] = map[i + 1][column];
					}
					map[i][column] = 0;
					row--;
				}
			}
			break;
		default:
			break;
		}
		map[row][column] = energy;
	}
	return 0;
}