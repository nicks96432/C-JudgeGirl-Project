#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000100
typedef struct Point
{
	int x;
	int y;
} point;
int distanceWithOrigin(point p)
{
	return p.x * p.x + p.y * p.y;
}
int comp(const void *x, const void *y)
{
	return distanceWithOrigin(*(point *)x) <
		   distanceWithOrigin(*(point *)y);
}
static point points[MAX_N];
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &points[i].x, &points[i].y);
	}
	qsort(points, n, sizeof(point), comp);
	int count = 1, max = 0, maxRadius, nowDistance = distanceWithOrigin(points[0]);
	for (i = 1; i < n; i++)
	{
		if (distanceWithOrigin(points[i]) == nowDistance)
		{
			count++;
		}
		else
		{
			if (count > max)
			{
				max = count;
				maxRadius = nowDistance;
			}
			count = 1;
			nowDistance = distanceWithOrigin(points[i]);
		}
	}
	printf("%d\n", maxRadius);
	return 0;
}