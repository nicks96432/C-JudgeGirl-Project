#include <stdio.h>
int main(void)
{
	int n, count1;
	unsigned int i;
	while (scanf("%d", &n) != EOF)
	{
		count1 = 0;
		for (i = 1; i < 2147483648; i *= 2)
		{
			if ((n & i) != 0)
			{
				count1++;
			}
		}
		printf("%d\n", count1);
	}
	return 0;
}