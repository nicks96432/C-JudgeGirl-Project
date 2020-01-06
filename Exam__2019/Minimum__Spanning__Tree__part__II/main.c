#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mstTA.h"
#define MAX_M 45
typedef struct Road
{
	int city1;
	int city2;
	int len;
	bool used;
} road;
typedef struct Roads
{
	road roads[MAX_M];
} ROADS;
int comp(const void *x, const void *y)
{
#ifdef ADD
	return ((((road *)x)->len) - (((road *)y)->len)) > 0 ? 1 : -1;
#elif defined REMOVE
	return ((((road *)x)->len) - (((road *)y)->len)) > 0 ? -1 : 1;
#endif
}
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	MSTTA mst;
	ROADS all, best;
	int count = 0, countBest = 0x7fffffff;
	initTA(&mst, n);
	int i, j, city1, city2, len;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &city1, &city2, &len);
#ifdef ADD
		all.roads[i] = (road){city1, city2, len, false};
#elif defined REMOVE
		count += len;
		addRoadTA(&mst, city1, city2, len);
		all.roads[i] = (road){city1, city2, len, true};
#endif
	}
	qsort(all.roads, m, sizeof(road), comp);
#ifdef ADD
	for (i = 0; i < m; i++)
	{
		if (!hasPathTA(&mst, all.roads[i].city1, all.roads[i].city2))
		{
			addRoadTA(&mst, all.roads[i].city1, all.roads[i].city2, all.roads[i].len);
			all.roads[i].used = true;
			count += all.roads[i].len;
		}
		if (connectedTA(&mst) && count < countBest)
		{
			best = all;
			countBest = count;
		}
	}
#endif
	for (i = 0; i < m; i++)
	{
		int tmp = removeRoadTA(&mst, all.roads[i].city1, all.roads[i].city2);
		all.roads[i].used = false;
		count -= tmp;
		if (connectedTA(&mst))
		{
			if (count < countBest)
			{
				best = all;
				countBest = count;
			}
		}
		else
		{
			addRoadTA(&mst, all.roads[i].city1, all.roads[i].city2, all.roads[i].len);
			all.roads[i].used = true;
			count += tmp;
		}
	}
	for (i = 0; i < m; i++)
	{
#ifdef ADD
		if (best.roads[i].used)
#elif defined REMOVE
		if (!best.roads[i].used)
#endif
		{
			printf("%d %d %d\n", best.roads[i].city1, best.roads[i].city2, best.roads[i].len);
		}
	}
	return 0;
}