#include <stdio.h>
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int column__highest = -1, column__second = -2;
	int column__highest__row, column__second__row;
	int highest = -2, highest__column = 0, highest__row = 0;
	int i, j, x;
	for (i = 1; i <= n; i++)
	{
		column__highest = -1;
		column__second = -2;
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &x);
			if (x > highest || (x == highest && i > highest__column) || (x == highest && (j > highest__row && i == highest__column)))
			{
				highest = x;
				highest__column = i;
				highest__row = j;
			}
			if (x >= column__highest)
			{
				column__second = column__highest;
				column__second__row = column__highest__row;
				column__highest = x;
				column__highest__row = j;
			}
			else if (x >= column__second)
			{
				column__second = x;
				column__second__row = j;
			}
		}
		printf("%d %d\n", column__highest__row, column__second__row);
	}
	printf("%d %d\n", highest__column, highest__row);
	return 0;
}