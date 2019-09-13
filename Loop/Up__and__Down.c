#include <stdio.h>
int main()
{
	int i, x;
	scanf("%d", &x);
	for (i = 1; i <= x; i++)
	{
		printf("%d\n", i);
	}
	for (i = x - 1; i > 0; i--)
	{
		printf("%d\n", i);
	}
	return 0;
}