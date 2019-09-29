#include <stdio.h>
#define abs(x) ((x) > (0) ? (x) : (-(x)))
int main(void)
{
	int ax, ay, bx, by, cx, cy, dx, dy;
	scanf("%d%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
	int area = abs(cx - ax) * abs(cy - ay) - abs(dx - ax) * abs(cy - dy) - abs(cx - bx) * abs(by - ay);
	int perimeter = abs(bx - ax) + abs(by - ay) + abs(cx - bx) + abs(cy - by) + abs(cx - dx) + abs(cy - dy) + abs(dx - ax) + abs(dy - ay);
	printf("%d\n%d", perimeter, area);
	return 0;
}