#include <stdio.h>
int main(void)
{
	int n, i, num, max, min;
	while (scanf("%d", &n) != EOF)
	{
		i = n;
		max = -2147483648;
		min = 2147483647;
		while (i-- && scanf("%d", &num) != EOF)
		{
			if (num > max)
			{
				max = num;
			}
			if (num < min)
			{
				min = num;
			}
		}
		if (i > 0)
		{
			printf("%d\n",min);
		}
		else
		{
			printf("%d\n", max);
		}
	}
	return 0;
}