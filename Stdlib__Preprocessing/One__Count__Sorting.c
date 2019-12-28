#include <stdio.h>
#include <stdlib.h>
int count1(long long x)
{
	int count = 0;
	for (int i = 0; i < 63; i++)
	{
		if (x & (1ULL << i))
		{
			count++;
		}
	}
	return count;
}
int comp(const void *x, const void *y)
{
	int count_x = count1(*(long long *)x);
	int count_y = count1(*(long long *)y);
	if (count_x == count_y)
	{
		return (*(long long *)x) > (*(long long *)y);
	}
	else
	{
		return count_x - count_y;
	}
}
int main(void)
{
	int countNum = 0;
	long long num[1000];
	while (scanf("%lld", &num[countNum]) != EOF)
	{
		countNum++;
	}
	qsort(num, countNum, sizeof(long long), comp);
	for (int i = 0; i < countNum; i++)
	{
		printf("%lld\n", num[i]);
	}
	return 0;
}