#include <stdio.h>
#include <stdbool.h>
#define abs(x) ((x) > (0) ? (x) : (-(x)))
int main(void)
{
	int i, len, count3 = 0, count11__odd = 0, count11__even = 0;
	signed char num[1003];
	while (scanf("%s", num))
	{
		count3 = 0;
		count11__odd = 0;
		count11__even = 0;
		if (num[0] == '-')
		{
			break;
		}
		for (i = 0;; i++)
		{
			if (num[i] == '\0')
			{
				len = i;
				break;
			}
		}
		if (!(num[len - 1] % 2))
		{
			printf("yes ");
		}
		else
		{
			printf("no ");
		}
		for (i = 0; i < len; i++)
		{
			count3 += num[i] - '0';
		}
		if (count3 % 3 == 0)
		{
			printf("yes ");
		}
		else
		{
			printf("no ");
		}
		if (num[len - 1] == '5' || num[len - 1] == '0')
		{
			printf("yes ");
		}
		else
		{
			printf("no ");
		}
		for (i = len - 1; i >= 0; i -= 2)
		{
			count11__odd += num[i] - '0';
		}
		for (i = len - 2; i >= 0; i -= 2)
		{
			count11__even += num[i] - '0';
		}
		// printf("%d %d ", count11__even, count11__odd);
		if (abs(count11__even - count11__odd) % 11 == 0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}