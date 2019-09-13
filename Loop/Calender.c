#include <stdio.h>
int main()
{
	int i, y, leap = 0, m, d, max__date;
	scanf("%d %d %d", &y, &m, &d);
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
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		max__date = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		max__date = 30;
		break;
	case 2:
		if (leap)
		{
			max__date = 29;
		}
		else
		{
			max__date = 28;
		}
	default:
		break;
	}
	if (m < 1 || m > 12 || d < 0)
	{
		printf("invalid");
	}
	else
	{
		printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
		for (i = 0; i < d; i++)
		{
			printf("   ");
		}
		for (i = 1; i <= max__date; i++)
		{
			if (d > 6)
			{
				printf("\n");
				d = 0;
			}
			printf("%3d", i);
			d++;
		}
		printf("\n=====================\n");
	}
	return 0;
}