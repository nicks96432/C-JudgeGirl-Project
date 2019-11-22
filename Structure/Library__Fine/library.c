#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "date.h"
static const int days[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
static void convert(struct Date date, int *ans)
{
	int leap, isleap;
	isleap = ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0);
	leap = (date.year - 1) / 4 - (date.year - 1) / 100 + (date.year - 1) / 400;
	*ans = days[date.month] + leap + date.day + (date.year - 1) * 365 + (date.month > 2) * isleap;
	return;
}
static int findfee(unsigned int importance)
{
	unsigned int i, count;
	for (i = 0x80000000U; i > 0; i >>= 1)
	{
		if (importance & i)
		{
			break;
		}
	}
	for (count = 0, i >>= 1; i > 0; i >>= 1, count++)
	{
		if (importance & i)
		{
			break;
		}
	}
	return count;
}
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
	int expire;
	switch (book.type)
	{
	case NOVEL:
		expire = 90;
		break;
	case COMICS:
		expire = 10;
		break;
	case MANUAL:
		expire = 100;
		break;
	case TEXTBOOK:
		expire = 5;
		break;
	default:
		exit(-1);
		break;
	}
	int from, to;
	convert(date_borrowed, &from);
	convert(date_returned, &to);
	if (to - from + 1 <= expire)
	{
		return 0;
	}
	return (to - from + 1 - expire) * findfee(book.importance);
}