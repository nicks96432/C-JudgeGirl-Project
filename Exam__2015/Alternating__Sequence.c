#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
int k, n, tmp = 0, ans = 0, count = 0, prev__sign = 0;
void update(int);
int main(void)
{
	int x;
	scanf("%d", &k);
	while (scanf("%d", &x) == 1 && x)
	{
		update(x);
	}
	update(0);
	printf("%d", ans * k);
}
void update(int x)
{
	if (x > 0)
	{
		if (prev__sign == 1)
		{
			count++;
		}
		else if (prev__sign == -1)
		{
			if (count == k)
			{
				tmp++;
			}
			else
			{
				tmp = 0;
			}
			count = 1;
			prev__sign = 1;
		}
		else
		{
			count = 1;
			prev__sign = 1;
			tmp = 0;
		}
	}
	else if (x < 0)
	{
		if (prev__sign == -1)
		{
			count++;
		}
		else if (prev__sign == 1)
		{
			if (count > k)
			{
				if (tmp >= 3)
				{
					ans = max(ans, tmp + 1);
				}
				tmp = 1;
				count = 1;
				prev__sign = -1;
			}
			else if (count < k)
			{
				tmp = -2147483647;
				count = 1;
				prev__sign = -1;
			}
			else
			{
				if (tmp < 0)
				{
					tmp = 0;
				}
				if (tmp + 1 >= 3)
				{
					ans = max(ans, tmp + 1);
				}
				tmp++;
				count = 1;
				prev__sign = -1;
			}
		}
		else
		{
			tmp = -2147483647;
			count = 1;
			prev__sign = -1;
		}
	}
	else
	{
		if (prev__sign == 0)
		{
			count++;
		}
		else if (prev__sign == 1)
		{
			if (count >= k)
			{
				if (tmp + 1 >= 3)
				{
					ans = max(ans, tmp + 1);
					tmp = -2147483647;
					count = 1;
					prev__sign = 0;
				}
			}
			else
			{
				tmp = -2147483647;
				count = 1;
				prev__sign = 0;
			}
		}
		else
		{
			tmp = -2147483647;
			count = 1;
			prev__sign = 0;
		}
	}
	return;
}