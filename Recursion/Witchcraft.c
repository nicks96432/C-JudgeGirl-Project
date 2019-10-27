#include <stdio.h>
#include <stdbool.h>
long long A, B, C, D;
bool craft(int, int, int, int, int);
int main(void)
{
	int a, b, c, n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d%lld%lld%lld", &D, &a, &b, &c, &A, &B, &C);
		bool yes = craft(0, a, b, c, 0);
		if (yes)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
bool craft(int size, int a, int b, int c, int now) /* now : 現在拿a,b,c哪一個 */
{
	int i;
	if (now > 2 || size > D)
	{
		return size == D;
	}
	if (now == 0)
	{
		for (i = 0; i <= a && size + i * A <= D; i++)
		{
			if (craft(size + i * A, a - 1, b, c, now + 1) == true)
			{
				return true;
			}
		}
	}
	if (now == 1)
	{
		for (i = 0; i <= b && size + i * B <= D; i++)
		{
			if (craft(size + i * B, a, b - 1, c, now + 1) == true)
			{
				return true;
			}
		}
	}
	if (now == 2)
	{
		for (i = 0; i <= c && size + i * C <= D; i++)
		{
			if (craft(size + i * C, a, b, c - 1, now + 1) == true)
			{
				return true;
			}
		}
	}
	return false;
}