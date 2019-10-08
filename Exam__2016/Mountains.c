#include <stdio.h>
int main(void)
{
	int i, n, x, prev = 0, prevprev = 0, ans = 0;
	scanf("%d", &n);
	scanf("%d%d", &prevprev, &prev);
	if (prevprev < prev)
	{
		ans += (prev - prevprev) * 3;
	}
	else
	{
		ans += (prevprev - prev) * 2;
	}
	for (i = 2; i < n; i++)
	{
		scanf("%d", &x);
		if (prevprev < prev)
		{
			if (prev < x)
			{
				ans += (x - prev) * 4;
			}
			else
			{
				ans += (prev - x) * 3;
			}
		}
		else
		{
			if (prev < x)
			{
				ans += (x - prev) * 3;
			}
			else
			{
				ans += (prev - x) * 2;
			}
		}
		prevprev = prev;
		prev = x;
	}
	printf("%d", ans);
}