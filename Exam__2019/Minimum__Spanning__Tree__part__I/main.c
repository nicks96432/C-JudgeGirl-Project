#include <stdio.h>
#include "mst.h"
int main(void)
{
	int n, m;
	MST mst;
	scanf("%d%d", &n, &m);
	init(&mst, n);
	for (int i = 0, j, k, l, s; i < m; i++)
	{
		scanf("%d", &j);
		switch (j)
		{
		case 0:
			scanf("%d%d%d", &k, &l, &s);
			addRoad(&mst, k, l, s);
			printf("%d Add road.\n", i);
			break;
		case 1:
			scanf("%d%d", &k, &l);
			s = removeRoad(&mst, k, l);
			printf("%d Remove road of length %d.\n", i, s);
			break;
		case 2:
			s = connected(&mst);
			printf("%d MST is %sconnected.\n", i, s ? "" : "not ");
			break;
		case 3:
			scanf("%d%d", &k, &l);
			s = hasPath(&mst, k, l);
			printf("%d There is %sa path.\n", i, s ? "" : "not ");
			break;
		}
	}
	return 0;
}