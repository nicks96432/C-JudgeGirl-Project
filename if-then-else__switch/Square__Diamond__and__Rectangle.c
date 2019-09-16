#include <stdio.h>
typedef struct
{
	int x;
	int y;
} point;
typedef struct
{
	int x;
	int y;
	int len;
} vec;

_Bool dot(vec p1, vec p2)
{
	return (p1.x * p2.x + p1.y * p2.y) == 0 ? 1 : 0;
}
_Bool area(point p1, point p2, point p3)
{
	return (p2.x * p3.y + p1.x * p2.y + p3.x * p1.y - p2.x * p1.y - p3.x * p2.y - p1.x * p3.y) > 0 ? 1 : 0;
}
int main(void)
{
	point a, b, c, d;
	vec ab, bc, cd, da;
	_Bool abc, abd, acd, bcd;
	int n, tmp;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d %d %d %d %d %d %d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
		abc = area(a, b, c);
		abd = area(a, b, d);
		acd = area(a, c, d);
		bcd = area(b, c, d);
		// 註解為以A為基準，逆時針排列
		// ABDC ACDB
		if ((abc != 0 && abd != 0 && acd == 0 && bcd == 0) || (abc == 0 && abd == 0 && acd != 0 && bcd != 0))
		{
			tmp = c.x;
			c.x = d.x;
			d.x = tmp;
			tmp = c.y;
			c.y = d.y;
			d.y = tmp;
		}
		else if (abc != 0 && abd == 0 && acd == 0 && bcd != 0)//ADBC
		{
			tmp = a.x;
			a.x = d.x;
			d.x = tmp;
			tmp = a.y;
			a.y = d.y;
			d.y = tmp;
		}
		else if (abc == 0 && abd == 0 && acd == 0 && bcd == 0)//ADCB
		{
			tmp = b.x;
			b.x = d.x;
			d.x = tmp;
			tmp = b.y;
			b.y = d.y;
			d.y = tmp;
		}
		else if (abc == 0 && abd != 0 && acd != 0 && bcd == 0)//ACBD
		{
			tmp = b.x;
			b.x = c.x;
			c.x = tmp;
			tmp = b.y;
			b.y = c.y;
			c.y = tmp;
		}
		ab.x = b.x - a.x;
		ab.y = b.y - a.y;
		ab.len = ab.x * ab.x + ab.y * ab.y;
		bc.x = c.x - b.x;
		bc.y = c.y - b.y;
		bc.len = bc.x * bc.x + bc.y * bc.y;
		cd.x = d.x - c.x;
		cd.y = d.y - c.y;
		cd.len = cd.x * cd.x + cd.y * cd.y;
		da.x = a.x - d.x;
		da.y = a.y - d.y;
		da.len = da.x * da.x + da.y * da.y;
		if (ab.len == bc.len && bc.len == cd.len && cd.len == da.len)
		{
			if (dot(ab, bc) != 0 && dot(bc, cd) != 0 && dot(cd, da) != 0)
			{
				printf("square\n");
			}
			else
			{
				printf("diamond\n");
			}
		}
		else if (ab.len == cd.len && da.len == bc.len && dot(ab, bc) != 0 && dot(bc, cd) != 0 && dot(cd, da) != 0)
		{
			printf("rectangle\n");
		}
		else
		{
			printf("other\n");
		}
	}
	return 0;
}