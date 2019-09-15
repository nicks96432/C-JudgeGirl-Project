#include <stdio.h>
int selection(int, int);
int combination(const int, const int);
int gcd(int, int);
int main(void)
{
	int m, n;
	scanf("%d%d", &n, &m);
	printf("%d", selection(n, m));
	return 0;
}
int selection(int n, int m)
{
	int i, ans = 0;
	for (i = 0; i <= m; i++)
	{
		ans += combination(n, i);
	}
	return ans;
}
int combination(const int n, const int r)
{
	int i, ans, ans__up = 1, ans__down = 1, Gcd;
	for (i = 1; i <= r; i++)
	{
		ans__up *= (n - i+1);
		ans__down *= i ;
		Gcd = gcd(ans__up, ans__down);
		ans__up /= Gcd;
		ans__down /= Gcd;
	}
	ans = ans__up / ans__down;
	return ans;
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
