#include <stdio.h>
#include <stdlib.h>
#include "count_day.h"
int main(void)
{
	int year, day, month, results[7] = {0}, i;

	while (scanf("%d %d %d", &year, &day, &month) != EOF)
	{
		for (i = 0; i < 7; i++)
		{
			results[i] = 0;
		}
		count_day(year, day, month, results);
		for (i = 0; i < 6; i++)
		{
			printf("%d ", results[i]);
		}
		printf("%d\n", results[i]);
	}
	return 0;
}