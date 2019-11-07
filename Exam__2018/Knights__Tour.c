#include <stdio.h>
#include <string.h>
#define MAX_KNIGHTS 10001
#define MAX_COLUMN 100
int decide(int, int[][MAX_COLUMN], int[][2], int);
const int movements[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int main(void)
{
	int i, j, n, m;
	int stop = 0, decision, index = 0;
	int chessboard[MAX_COLUMN][MAX_COLUMN];
	int position[MAX_KNIGHTS][2];
	int finish[MAX_KNIGHTS], count__step[MAX_KNIGHTS];
	memset(chessboard, 0, sizeof(chessboard));
	memset(position, -1, sizeof(position));
	memset(finish, 0, sizeof(finish));
	memset(count__step, 0, sizeof(count__step));
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &position[i][0], &position[i][1]);
	}
	for (i = 0; i < m; i++)
	{
		chessboard[position[i][0]][position[i][1]] = 10000 * (i + 1);
		count__step[i]++;
	}
	while (1)
	{
		if (finish[index])
		{
			index++;
			index %= m;
			continue;
		}
		decision = decide(index, chessboard, position, n);
		if (decision == 0)
		{
			finish[index] = 1;
#ifdef DEBUG
			printf("finish:%d\n", index + 1);
#endif
			stop++;
		}
		else
		{
			position[index][0] += movements[decision - 1][0];
			position[index][1] += movements[decision - 1][1];
			chessboard[position[index][0]][position[index][1]] = 10000 * (index + 1) + count__step[index];
			count__step[index]++;
		}
		index++;
		index %= m;
		if (stop == m)
		{
			break;
		}
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
int decide(int index, int chessboard[][MAX_COLUMN], int position[][2], int n)
{
	int max__p = 0x3f3f3f3f, max__decision = 0;
	int next__column, next__row, count;
	int nextnext__column, nextnext__row;
	int i, j;
	for (i = 0; i < 8; i++)
	{
		next__row = position[index][0] + movements[i][0];
		next__column = position[index][1] + movements[i][1];
		if (next__column < 0 || next__row < 0 || next__column >= n || next__row >= n || chessboard[next__row][next__column])
		{
			continue;
		}
		count = 0;
		for (j = 0; j < 8; j++)
		{
			nextnext__row = next__row + movements[j][0];
			nextnext__column = next__column + movements[j][1];
			if (nextnext__column < 0 || nextnext__row < 0 || nextnext__column >= n || nextnext__row >= n || chessboard[nextnext__row][nextnext__column])
			{
				continue;
			}
			count++;
		}
		if (count < max__p)
		{
			max__p = count;
			max__decision = i + 1;
#ifdef DEBUG
			printf("%d %d\n", max__p, max__decision);
#endif
		}
	}
	return max__decision;
}