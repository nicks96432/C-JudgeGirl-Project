#include <stdio.h>
int gcd(int, int);
int main(void)
{
	int a, b,Gcd;
	scanf("%d", &a);
	while (scanf("%d", &b) == 1)
	{
		Gcd = gcd(a, b);
		a *= b;
		a /= Gcd;
	}
	printf("%d", a);
	return 0;
}
int gcd(int tmp1, int tmp2)
{
	int Gcd;
	while (tmp1 != 0 && tmp2 != 0)
	{
		if (tmp1 >= tmp2)
		{
			tmp1 %= tmp2;
		}
		else
		{
			tmp2 %= tmp1;
		}
	}
	if (tmp1 >= tmp2)
	{
		Gcd = tmp1;
	}
	else
	{
		Gcd = tmp2;
	}
	return Gcd;
}