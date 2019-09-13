#include <stdio.h>
typedef struct
{
	int x;
	int y;
} point;
int abs(int a)
{
	return a > 0 ? a : -a;
}
int determinant(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
int main()
{
	point a, b, c, d, ab, ad, cb, cd;
	int abo, bco, cdo, dao, area;
	scanf("%d %d %d %d %d %d %d %d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
	abo = abs(determinant(a, b));
	bco = abs(determinant(b, c));
	cdo = abs(determinant(c, d));
	dao = abs(determinant(d, a));
	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	ad.x = d.x - a.x;
	ad.y = d.y - a.y;
	cb.x = b.x - c.x;
	cb.y = b.y - c.y;
	cd.x = d.x - c.x;
	cd.y = d.y - c.y;
	area = abs(determinant(ab, ad)) + abs(determinant(cb, cd));
	if (area == abo + bco + cdo + dao)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	return 0;
}
