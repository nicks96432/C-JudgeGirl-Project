#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Point
{
	int x;
	int y;
} point;
int dist(point *a, point *b)
{
	return (b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y);
}
int comp(const void *x, const void *y)
{
	point *a = (point *)x;
	point *b = (point *)y;
	point zero = {0, 0};
	int dist_a = dist(a, &zero);
	int dist_b = dist(b, &zero);
	if (dist_a == dist_b)
	{
		if (a->x > b->x || (a->x == b->x && a->y > b->y))
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return dist_a - dist_b;
	}
}
int main(void)
{
	point cities[100000];
	point tmp;
	int countPoint = 0;
	while (scanf("%d%d", &cities[countPoint].x, &cities[countPoint].y) == 2)
	{
		countPoint++;
	}
	qsort(cities, countPoint, sizeof(point), comp);
	point zero = {0, 0};
	int ans = dist(&cities[0], &zero);
	for (int i = 1; i < countPoint; i++)
	{
		ans += dist(&cities[i], &cities[i - 1]);
	}
	printf("%d\n", ans);
	return 0;
}