#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(void)
{
	const int commands[][3] = {{0, 0, 0}, {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	int mx, my, mz, bx, by, bz;
	scanf("%d%d%d%d%d%d", &mx, &my, &mz, &bx, &by, &bz);
	int n, dist;
	bool blackhole = false;
	scanf("%d", &n);
	int i, command;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &command);
		x += commands[command][0];
		y += commands[command][1];
		z += commands[command][2];
		dist = abs(x - mx) + abs(y - my) + abs(z - mz);
		if (dist < 10)
		{
			return 0;
		}
		dist = abs(x - bx) + abs(y - by) + abs(z - bz);
		if (dist < 10 && !blackhole)
		{
			x = bx;
			y = by;
			z = bz;
			blackhole = true;
		}
		if (i % 5 == 4)
		{
			printf("%d %d %d\n", x, y, z);
		}
	}
	return 0;
}