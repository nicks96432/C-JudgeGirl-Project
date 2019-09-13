#include <stdio.h>
int main(void)
{
	int i;
	long long int x, tmp;
	scanf("%lld %d", &x, &i);
	tmp = x;
	while (i-- > 1)
	{
		x *= tmp;
	}
	printf("%d", x);
	return 0;
}