#include <string.h>
#include "Game__of__Cell.h"
void game_of_cell(int grid[50][50], int outcome[50][50], int N)
{
	int i, j;
	const int next[3][9] = {{0, 0, 0, 2, 0, 0, 0, 0, 0}, {1, 1, 2, 1, 1, 1, 1, 1, 1}, {0, 0, 2, 2, 1, 1, 1, 1, 1, 1}};
	int map[52][52] = {}, countalive[52][52];
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
		{
			map[i + 1][j + 1] = grid[i][j];
		}
	}
	int n;
	for (n = 0; n < N; n++)
	{
		memset(countalive, 0, sizeof(countalive));
		for (i = 1; i <= 50; i++)
		{
			for (j = 1; j <= 50; j++)
			{
				countalive[i][j] += map[i + 1][j] / 2;
				countalive[i][j] += map[i - 1][j] / 2;
				countalive[i][j] += map[i][j + 1] / 2;
				countalive[i][j] += map[i][j - 1] / 2;
				countalive[i][j] += map[i - 1][j - 1] / 2;
				countalive[i][j] += map[i - 1][j + 1] / 2;
				countalive[i][j] += map[i + 1][j - 1] / 2;
				countalive[i][j] += map[i + 1][j + 1] / 2;
			}
		}
		for (i = 1; i <= 50; i++)
		{
			for (j = 1; j <= 50; j++)
			{
				map[i][j] = next[map[i][j]][countalive[i][j]];
			}
		}
	}
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
		{
			outcome[i][j] = map[i + 1][j + 1];
		}
	}
	return;
}
