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
	int len2;
} vec;

int main(void)
{
	int i, n;
	point a[10], b[10], c[10];
	vec ab[10], bc[10], ca[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d %d %d", &a[i].x, &a[i].y, &b[i].x, &b[i].y, &c[i].x, &c[i].y);
		ab[i].x = b[i].x - a[i].x;
		ab[i].y = b[i].y - a[i].y;
		bc[i].x = c[i].x - b[i].x;
		bc[i].y = c[i].y - b[i].y;
		ca[i].x = a[i].x - c[i].x;
		ca[i].y = a[i].y - c[i].y;
		ab[i].len2 = ab[i].x * ab[i].x + ab[i].y * ab[i].y;
		bc[i].len2 = bc[i].x * bc[i].x + bc[i].y * bc[i].y;
		ca[i].len2 = ca[i].x * ca[i].x + ca[i].y * ca[i].y;
	}
	for (i = 0; i < n; i++)
	{
		if (ab[i].len2 == bc[i].len2 || bc[i].len2 == ca[i].len2 || ca[i].len2 == ab[i].len2)
		{
			printf("isosceles\n");
		}
		else if (ab[i].len2 + bc[i].len2 == ca[i].len2 || bc[i].len2 + ca[i].len2 == ab[i].len2 || ca[i].len2 + ab[i].len2 == bc[i].len2)
		{
			printf("right\n");
		}
		else if (ab[i].len2 + bc[i].len2 > ca[i].len2 && bc[i].len2 + ca[i].len2 > ab[i].len2 && ca[i].len2 + ab[i].len2 > bc[i].len2)
		{
			printf("acute\n");
		}
		else
		{
			printf("obtuse\n");
		}
	}
	return 0;
}