#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define determinant(ax, ay, bx, by) (((ax) * (by)) - ((ay) * (bx)))
int main(void)
{
	int ax, ay, bx, by, cx, cy;
	int maxx, maxy, minx, miny;
	int count = 0, x, y, check, checkx, checky, determinant__ab, determinant__bc, determinant__ca;
	scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
	maxx = max(ax, max(bx, cx));
	maxy = max(ay, max(by, cy));
	minx = min(ax, min(bx, cx));
	miny = min(ay, min(by, cy));
	for (x = minx; x <= maxx; x++)
	{
		for (y = miny; y <= maxy; y++)
		{
			for (check = 0; check < 4; check++)
			{
				if (check == 0)
				{
					checkx = x;
					checky = y;
				}
				else if (check == 1)
				{
					checkx = x + 1;
					checky = y;
				}
				else if (check == 2)
				{
					checkx = x;
					checky = y - 1;
				}
				else if (check == 3)
				{
					checkx = x + 1;
					checky = y - 1;
				}
				determinant__ab = determinant(ax - checkx, ay - checky, bx - checkx, by - checky);
				determinant__bc = determinant(bx - checkx, by - checky, cx - checkx, cy - checky);
				determinant__ca = determinant(cx - checkx, cy - checky, ax - checkx, ay - checky);
				if (!((determinant__ab <= 0 && determinant__bc <= 0 && determinant__ca <= 0) || (determinant__ab >= 0 && determinant__bc >= 0 && determinant__ca >= 0)))
				{
					break;
				}
			}
			if (check == 4)
			{
				count++;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}