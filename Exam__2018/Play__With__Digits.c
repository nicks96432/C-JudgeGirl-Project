#include <stdio.h>
#define abs(x) ((x) > (0) ? (x) : (-(x)))
int main(void)
{
	int n;
	_Bool is__even, odd__flag = 0, eleven;
	int count__digit = 0, count__zero = 0, count11__odd = 0, count11__even = 0;
	while (scanf("%d", &n) != EOF)
	{
		count__digit++;
		if (n == 0)
		{
			count__zero++;
		}
		if (odd__flag)
		{
			count11__odd += n;
			odd__flag = 0;
		}
		else
		{
			count11__even += n;
			odd__flag = 1;
		}
	}
	if (!(n % 2))
	{
		is__even = 1;
	}
	else
	{
		is__even = 0;
	}
	if (abs(count11__even - count11__odd) % 11 == 0)
	{
		eleven = 1;
	}
	else
	{
		eleven = 0;
	}
	printf("%d\n%d\n%d\n%d", count__digit, is__even, count__zero, eleven);
	return 0;
}