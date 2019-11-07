#include "validMoveNum.h"
int validMoveNum(int r, int c, int n, int visited[100][100])
{
	if (r < 0 || c < 0 || r >= n || c >= n || visited[r][c])
	{
		return -1;
	}
	const int movements[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
	int i, ans = 0, next__column, next__row;
	for (i = 0; i < 8; i++)
	{
		next__row = r + movements[i][0];
		next__column = c + movements[i][1];
		if (next__column < 0 || next__row < 0 || next__column >= n || next__row >= n || visited[next__row][next__column] != 0)
		{
			continue;
		}
		ans++;
	}
	return ans;
}