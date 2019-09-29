#include <stdio.h>
int main(void)
{
	long long int n;
	int count1;
	unsigned long long int i;
	while (scanf("%lld", &n) != EOF)
	{
		count1 = 0;
		for (i = 1; i < 9223372036854775808; i *= 2)
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