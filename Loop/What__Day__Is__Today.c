#include <stdio.h>
typedef struct day
{
	int month;
	int day;
} day;
int main()
{
	int i, leap = 0, y, weekday, n;
	scanf("%d %d %d", &y, &weekday, &n);
	int total__day[n], ans[n], month__error[n], day__error[n];
	day d[n];
	if (!(y % 4))
	{
		leap = 1;
		if (!(y % 100))
		{
			leap = 0;
		}
		if (!(y % 400))
		{
			leap = 1;
		}
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &d[i].month, &d[i].day);
		ans[i] = 0;
		total__day[i] = 0;
		day__error[i] = 0;
		month__error[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		switch (d[i].month)
		{
		case 0:
			month__error[i] = 1;
			break;
		case 1:
			if (d[i].day <= 31 && d[i].day >= 1)
			{
				total__day[i] = d[i].day;
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 2:
			if ((leap && d[i].day <= 29 && d[i].day >= 1) || (!(leap) && d[i].day <= 28 && d[i].day >= 1))
			{
				total__day[i] = 31 + d[i].day;
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 3:
			if (d[i].day <= 31 && d[i].day >= 1)
			{
				if (leap)
				{
					total__day[i] = 60 + d[i].day;
				}
				else
				{
					total__day[i] = 59 + d[i].day;
				}
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 4:
			if (d[i].day <= 30 && d[i].day >= 1)
			{
				if (leap)
				{
					total__day[i] = 91 + d[i].day;
				}
				else
				{
					total__day[i] = 90 + d[i].day;
				}
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 5:
			if (d[i].day <= 31 && d[i].day >= 1)
			{
				if (leap)
				{
					total__day[i] = 121 + d[i].day;
				}
				else
				{
					total__day[i] = 120 + d[i].day;
				}
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 6:
			if (d[i].day <= 30 && d[i].day >= 1)
			{
				if (leap)
				{
					total__day[i] = 152 + d[i].day;
				}
				else
				{
					total__day[i] = 151 + d[i].day;
				}
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 7:
			if (d[i].day <= 31 && d[i].day >= 1)
			{
				if (leap)
				{
					total__day[i] = 182 + d[i].day;
				}
				else
				{
					total__day[i] = 181 + d[i].day;
				}
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 8:
			if (d[i].day <= 31 && d[i].day >= 1)
			{
				if (leap)
				{
					total__day[i] = 213 + d[i].day;
				}
				else
				{
					total__day[i] = 212 + d[i].day;
				}
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 9:
			if (d[i].day <= 30 && d[i].day >= 1)
			{
				if (leap)
				{
					total__day[i] = 244 + d[i].day;
				}
				else
				{
					total__day[i] = 243 + d[i].day;
				}
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 10:
			if (d[i].day <= 31 && d[i].day >= 1)
			{
				if (leap)
				{
					total__day[i] = 274 + d[i].day;
				}
				else
				{
					total__day[i] = 273 + d[i].day;
				}
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 11:
			if (d[i].day <= 30 && d[i].day >= 1)
			{
				if (leap)
				{
					total__day[i] = 305 + d[i].day;
				}
				else
				{
					total__day[i] = 304 + d[i].day;
				}
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		case 12:
			if (d[i].day <= 31 && d[i].day >= 1)
			{
				if (leap)
				{
					total__day[i] = 335 + d[i].day;
				}
				else
				{
					total__day[i] = 334 + d[i].day;
				}
			}
			else
			{
				day__error[i] = 1;
			}
			break;
		default:
			month__error[i] = 1;
			break;
		}
		if (month__error[i] == 1)
		{
			ans[i] = -1;
		}
		else if (day__error[i] == 1)
		{
			ans[i] = -2;
		}
		else
		{
			ans[i] = (total__day[i] + weekday - 1) % 7;
		}
		printf("%d\n", ans[i]);
	}
	return 0;
}