#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int a, b, c, d, e, c__func, c1 = -2147483647, c2 = 2147483647, c3 = -2147483647, count__c, tmp1 = 0, tmp2 = 0, tmp3 = 0;
	bool is__consecutive = false;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	int n;
	while (scanf("%d", &n) != EOF)
	{
		count__c = 0;
		c__func = n;
		while (1)
		{
			if (c__func >= d && c__func <= e)
			{
				break;
			}
			c__func = (a * c__func + b) % c;
			count__c++;
		}
		if ((c3 == c2 + 1 && c3 == c1 - 1) || (c3 == c2 - 1 && c3 == c1 + 1) || (c2 == c3 + 1 && c2 == c1 - 1) || (c2 == c3 - 1 && c2 == c1 + 1) || (c1 == c3 + 1 && c1 == c2 - 1) || (c1 == c3 - 1 && c1 == c2 + 1))
		{
			printf("%d %d %d", tmp1, tmp2, tmp3);
			is__consecutive = true;
			return 0;
		}
		tmp1 = tmp2;
		c1 = c2;
		tmp2 = tmp3;
		c2 = c3;
		tmp3 = n;
		c3 = count__c;
	}
	if ((c3 == c2 + 1 && c3 == c1 - 1) || (c3 == c2 - 1 && c3 == c1 + 1) || (c2 == c3 + 1 && c2 == c1 - 1) || (c2 == c3 - 1 && c2 == c1 + 1) || (c1 == c3 + 1 && c1 == c2 - 1) || (c1 == c3 - 1 && c1 == c2 + 1))
	{
		printf("%d %d %d", tmp1, tmp2, tmp3);
		is__consecutive = true;
		return 0;
	}
	if (!is__consecutive)
	{
		printf("Not found");
	}
	return 0;
}