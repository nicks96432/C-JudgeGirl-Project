#include <stdio.h>
#include <string.h>
#include "nextMove.h"
#include "validMoveNum.h"
#define MAX_KNIGHTS 10002
#define MAX_ROWS 100
int main(void)
{
	int n, m;
	int i, j, chessboard[MAX_ROWS][MAX_ROWS], position[MAX_KNIGHTS][2], finished[MAX_KNIGHTS], count__step = 1;
	const int movements[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
	memset(chessboard, 0, sizeof(chessboard));
	memset(position, 0, sizeof(position));
	memset(finished, 0, sizeof(finished));
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &position[i][0], &position[i][1]);
	}
	for (i = 0; i < m; i++)
	{
		chessboard[position[i][0]][position[i][1]] = 10000 * (i + 1);
	}
	int stop = 0, next;
	while (1)
	{
		for (i = 0; i < m; i++)
		{
			if (finished[i])
			{
				continue;
			}
			next = nextMove(position[i][0], position[i][1], n, chessboard);
			if (next == -1)
			{
				finished[i] = 1;
				stop++;
			}
			else
			{
				position[i][0] += movements[next][0];
				position[i][1] += movements[next][1];
				chessboard[position[i][0]][position[i][1]] = 10000 * (i + 1) + count__step;
			}
		}
		if (stop >= m)
		{
			break;
		}
		count__step++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			printf("%d ", chessboard[i][j]);
		}
		printf("%d\n", chessboard[i][j]);
	}
	return 0;
}