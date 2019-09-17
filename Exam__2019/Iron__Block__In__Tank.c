#include <stdio.h>
int main(void)
{
	int a, b, c, d, e, f, g, ans;
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
	if (d == 0)
	{
		ans = 0;
	}
	else if (a * b > e * f)
	{
		if (a * b * g <= (e * f + a * b) * c)
		{
			ans = d + e * f * g / (a * b);
			if (ans > c)
			{
				ans = c;
			}
		}
		else
		{
			ans = a * b * d / (a * b - e * f);
			if (ans > c)
			{
				ans = c;
			}
		}
	}
	else
	{
		ans = g + d;
		if (g >c)
		{
			ans = 0;
		}
		else if (ans > c)
		{
			ans = c;
		}
	}
	printf("%d", ans);
	return 0;
}