#include <stdio.h>
int main(void)
{
	int m;
	scanf("%d", &m);
	if (!(m % 2) && m > 0 && (m > 10000 || m < 1000))
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	return 0;
}