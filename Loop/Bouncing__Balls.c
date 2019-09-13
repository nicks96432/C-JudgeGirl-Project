#include <stdio.h>
int main(void)
{
	int i, X, Y, x1, y1, x2, y2, dx1, dy1, dx2, dy2, t;
	scanf("%d %d %d %d %d %d %d %d %d %d %d", &X, &Y, &x1, &y1, &x2, &y2, &dx1, &dy1, &dx2, &dy2, &t);
	for (i = 0; i < t; i++)
	{
		x1 += dx1;
		y1 += dy1;
		x2 += dx2;
		y2 += dy2;
		// printf("%d\t%d\t%d\t%d\n", x1, y1, x2, y2);
		// hit each other
		if (x1 == x2 && y1 == y2)
		{
			// 正面碰撞
			if (dx1 == -dx2 && dy1 == -dy2)
			{
				dx1 = -dx1;
				dx2 = -dx2;
				dy1 = -dy1;
				dy2 = -dy2;
			}
			// 側面碰撞
			else if (dx1 == dx2 && dy1 == -dy2)
			{
				dy1 = -dy1;
				dy2 = -dy2;
			}
			else if (dx1 == -dx2 && dy1 == dy2)
			{
				dx1 = -dx1;
				dx2 = -dx2;
			}
		}
		// hit walls
		if (x1 == 1 || x1 == X)
		{
			if (y1 == 1 || y1 == Y)
			{
				dx1 = -dx1;
				dy1 = -dy1;
			}
			else
			{
				dx1 = -dx1;
			}
		}
		else if (y1 == 1 || y1 == Y)
		{
			dy1 = -dy1;
		}
		if (x2 == 1 || x2 == X)
		{
			if (y2 == 1 || y2 == Y)
			{
				dx2 = -dx2;
				dy2 = -dy2;
			}
			else
			{
				dx2 = -dx2;
			}
		}
		else if (y2 == 1 || y2 == Y)
		{
			dy2 = -dy2;
		}
	}
	printf("%d\n%d\n%d\n%d\n", x1, y1, x2, y2);
	return 0;
}
// Note that by our rules two balls exchanging positions do not collide.
// If the ball hits a corner, it bounces back the way it came in.
// If two balls hit into each other, their positions are the same after they move into their new locations.
// 箱子左下角在(1,1)
/*
   (1,Y)_________________________________(X,Y)
		|								|
		|								|
		|								|
		|								|
		|								|
		|								|
		|								|
		|								|
   (1,1)_________________________________(X,1)
 */