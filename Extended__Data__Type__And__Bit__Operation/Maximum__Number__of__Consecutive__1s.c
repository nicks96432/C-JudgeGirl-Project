#include <stdio.h>
int main(void)
{
	int n, count1, max = -2147483647;
	unsigned int i;
	while (scanf("%d", &n) != EOF)
	{
		max=0;
		count1 = 0;
		for (i = 1; i < 2147483648; i *= 2)
		{
			if ((n & i) != 0)
			{
				count1++;
			}
			else
			{
				count1 = 0;
			}
			if (count1 > max)
			{
				max = count1;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}