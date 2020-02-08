#include <stdio.h>
#include <stdlib.h>
#include "activity.h"
static int comp(const void *x, const void *y)
{
	Activity *a = (Activity *)x, *b = (Activity *)y;
	if (a->end < b->end)
	{
		return -1;
	}
	else if (a->end > b->end)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int select(Activity activities[], int n)
{
	if (n == 0)
	{
		return 0;
	}
	qsort(activities, n, sizeof(Activity), comp);
	int ans = 0, now = activities[0].start;
	for (int i = 0; i < n; i++)
	{
		if (activities[i].start >= now)
		{
#ifdef PRINT
			printf("%d %d\n", activities[i].start, activities[i].end);
#endif
			now = activities[i].end;
			ans++;
		}
	}
	return ans;
}