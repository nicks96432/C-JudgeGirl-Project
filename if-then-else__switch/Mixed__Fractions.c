#include <stdio.h>
int gcd(int x, int y)
{
	int tmp;
	while (x % y != 0)
	{
		tmp = y;
		y = x % y;
		x = tmp;
	}
	return y;
}
int abs(int x)
{
	return x > 0 ? x : -x;
}
int main()
{
	int a, b, c, d, e, f, g, ans = 0, ans__up = 0, ans__down, gcdnum;
	scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
	switch (d)
	{
	case 0: //add
		if (a > 0)
		{
			b += a * c;
		}
		else
		{
			b = -b + a * c;
		}
		if (e > 0)
		{
			f += e * g;
		}
		else
		{
			f = -f + e * g;
		}
		b *= g;
		f *= c;
		c *= g;
		b += f;
		gcdnum = gcd(abs(b), c);
		b /= gcdnum;
		c /= gcdnum;
		if (b > 0)
		{
			ans = b / c;
			ans__up = b % c;
		}
		else
		{
			ans = -(abs(b) / c);
			ans__up = abs(b) % c;
		}
		ans__down = c;
		break;
	case 1: //subtract
		e = -e;
		if (a > 0)
		{
			b += a * c;
		}
		else
		{
			b = -b + a * c;
		}
		if (e > 0)
		{
			f += e * g;
		}
		else
		{
			f = -f + e * g;
		}
		b *= g;
		f *= c;
		c *= g;
		b += f;
		gcdnum = gcd(abs(b), c);
		b /= gcdnum;
		c /= gcdnum;
		if (b > 0)
		{
			ans = b / c;
			ans__up = b % c;
		}
		else
		{
			ans = -(abs(b) / c);
			ans__up = abs(b) % c;
		}
		ans__down = c;
		break;
	case 2: //multiply
		if (a > 0)
		{
			b += a * c;
		}
		else
		{
			b = -b + a * c;
		}
		if (e > 0)
		{
			f += e * g;
		}
		else
		{
			f = -f + e * g;
		}
		b *= f;
		c *= g;
		gcdnum = gcd(abs(b), c);
		b /= gcdnum;
		c /= gcdnum;
		if (b > 0)
		{
			ans = b / c;
			ans__up = b % c;
		}
		else
		{
			ans = -(abs(b) / c);
			ans__up = abs(b) % c;
		}
		ans__down = c;
		break;
	case 3: //devide
		if (a > 0)
		{
			b += a * c;
		}
		else
		{
			b = -b + a * c;
		}
		if (e > 0)
		{
			f += e * g;
		}
		else
		{
			f = -f + e * g;
		}
		b *= g;
		c *= f;
		gcdnum = gcd(abs(b), c);
		b /= gcdnum;
		c /= gcdnum;
		if (b > 0)
		{
			ans = b / c;
			ans__up = b % c;
		}
		else
		{
			ans = -(abs(b) / c);
			ans__up = abs(b) % c;
		}
		ans__down = c;
		break;
	default:
		break;
	}
	printf("%d\n%d\n%d", ans, ans__up, ans__down);
	return 0;
}