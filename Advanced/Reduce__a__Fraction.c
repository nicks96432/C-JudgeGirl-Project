#include <stdio.h>
int gcd(int a, int b)
{
	int tmp;
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
int main(void)
{
	int a, b, Gcd;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		Gcd = gcd(a, b);
		printf("%d / %d\n", a / Gcd, b / Gcd);
	}
	return 0;
}