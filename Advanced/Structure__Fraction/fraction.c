#include "fraction.h"
long long gcd(long long a, long long b)
{
	long long tmp;
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
Frac normal(long long a, long long b)
{
	long long Gcd = gcd(a, b);
	Frac ans;
	ans.a = a / Gcd;
	ans.b = b / Gcd;
	return ans;
}
Frac add(Frac x, Frac y)
{
	long long Gcd = gcd(x.b, y.b);
	x.a *= y.b / Gcd;
	y.a *= x.b / Gcd;
	x.b *= y.b / Gcd;
	x.a += y.a;
	x = normal(x.a, x.b);
	return x;
}
Frac subtract(Frac x, Frac y)
{
	long long Gcd = gcd(x.b, y.b);
	x.a *= y.b / Gcd;
	y.a *= x.b / Gcd;
	x.b *= y.b / Gcd;
	x.a -= y.a;
	x = normal(x.a, x.b);
	return x;
}
Frac multipy(Frac x, Frac y)
{
	x.a *= y.a;
	x.b *= y.b;
	x = normal(x.a, x.b);
	return x;
}
Frac divide(Frac x, Frac y)
{
	x.a *= y.b;
	x.b *= y.a;
	x = normal(x.a, x.b);
	return x;
}