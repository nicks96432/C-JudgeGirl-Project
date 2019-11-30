#include "SpiralSnake.h"
void SpiralSnake(int N, int *snake, int *result)
{
	int i;
	const int directions[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
	int direction = 0, twice = 0, count = 1, tmpcount = 1;
	int x = N / 2, y = N / 2;
	result[x * N + y] = snake[0];
	for (i = 1; i < N * N; i++)
	{
		x += directions[direction][0];
		y += directions[direction][1];
		result[x * N + y] = snake[i];
		tmpcount--;
		if (tmpcount == 0)
		{
			direction = (direction + 1) % 4;
			if (twice == 0)
			{
				twice = 1;
				tmpcount = count;
			}
			else
			{
				twice = 0;
				count++;
				tmpcount = count;
			}
		}
	}
	return;
}