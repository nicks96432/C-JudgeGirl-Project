#include <stdio.h>
typedef struct Point
{
	int x;
	int y;
} point;
int main(void)
{
	point a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
	d.x = c.x + b.x - a.x;
	d.y = c.y + b.y - a.y;	
	e.x = c.x + a.x - b.x;
	e.y = c.y + a.y - b.y;
	f.x = b.x + a.x - c.x;
	f.y = b.y + a.y - c.y;
	printf("%d\n%d\n%d\n%d\n%d\n%d\n", d.x, d.y, e.x, e.y, f.x, f.y);
	return 0;
}