#include <stdio.h>
int main(void)
{
	int k;
	scanf("%d", &k);
	int n, one = 0, ten = 0;
	_Bool yes = 0;
	while (scanf("%d", &n) != EOF)
	{
		one += n;
		// printf("%d ", ten * 10 + one);
		if (ten * 10 + one >= k)
		{
			printf("%d\n", (ten * 10 + one) / k);
			one = (ten * 10 + one) % k;
			ten = one;
			one = 0;
			yes = 1;
		}
		else
		{
			if (yes)
			{
				printf("0\n");
			}
			ten += one;
			one = 0;
		}
	}
	if (!yes)
	{
		printf("0");
	}
	return 0;
}