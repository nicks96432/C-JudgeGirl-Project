#include <stdbool.h>
#include "count_day.h"

bool isleap(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
void count_day(int year, int day, int month, int results[7])
{
	int i;
	const int days[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	const int days__leap[14] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	if (isleap(year))
	{
		day += days__leap[month];
	}
	else
	{
		day += days[month];
	}
	day %= 7;
	switch (month)
	{
	case 2:
		for (i = 0; i < (isleap(year) ? 29 : 28); i++)
		{
			results[(i + day) % 7]++;
		}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		for (i = 0; i < 31; i++)
		{
			results[(i + day) % 7]++;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		for (i = 0; i < 30; i++)
		{
			results[(i + day) % 7]++;
		}
		break;
	default:
		break;
	}
	return;
}