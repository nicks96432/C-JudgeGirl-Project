#include <stdio.h>
int sum(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return sum(n - 1) + n * n;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", sum(n));
	return 0;
}