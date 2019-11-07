#include "validMoveNum.h"
#include "nextMove.h"
int nextMove(int r, int c, int n, int visited[100][100])
{
	const int movements[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
	int i, j, min__p = 0x3f3f3f3f, p, min__index = -1;
	for (i = 0; i < 8; i++)
	{
		p = validMoveNum(r + movements[i][0], c + movements[i][1], n, visited);
		if (p >= 0 && p < min__p)
		{
			min__p = p;
			min__index = i;
		}
	}
	return min__index;
}