#include <stdio.h>
int map[9][9] = {}, ans[11][11], found = 0;
const int directions[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
void minesweeper(int x, int y)
{
	if (found)
	{
		return;
	}
	int i, j, count, direction, check;
	if (x == 10)
	{
		x = 1;
		y++;
		/* 檢查地雷數和地圖是否相符，以及是否有無解的情況 */
		for (i = 1; i <= 9; i++)
		{
			for (j = 1; j <= 9; j++)
			{
				count = 0;
				check = 0;
				for (direction = 0; direction < 9; direction++)
				{
					count += ans[i + directions[direction][0]][j + directions[direction][1]];
					if (ans[i + directions[direction][0]][j + directions[direction][1]] == -1)
					{
						check = 1;
					}
				}
				if (!check && count != map[i - 1][j - 1])
				{
					return;
				}
			}
		}
	}
	if (y == 10)
	{
		for (i = 1; i <= 9; i++)
		{
			for (j = 1; j <= 9; j++)
			{
				printf("%d%c", ans[i][j], j == 9 ? '\n' : ' ');
			}
		}
		found = 1;
		return;
	}
	/* 不是地雷 */
	ans[y][x] = 0;
	minesweeper(x + 1, y);
	/* 是地雷 */
	ans[y][x] = 1;
	minesweeper(x + 1, y);
	/* 還不知道 */
	ans[y][x] = -1;
	return;
}
int main(void)
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			ans[i][j] = -1;
		}
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	minesweeper(1, 1);
	if (!found)
	{
		printf("no solution\n");
	}
	return 0;
}