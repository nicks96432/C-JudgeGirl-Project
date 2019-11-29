#include <stdio.h>
#include "game__of__cell.h"
int main(void)
{
	int grid[50][50] = {0}, outcome[50][50] = {0}, N;
	scanf("%d", &N);
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}
	game_of_cell(grid, outcome, N);
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			printf("%d%c", outcome[i][j], " \n"[j == 49]);
		}
	}
	return 0;
}