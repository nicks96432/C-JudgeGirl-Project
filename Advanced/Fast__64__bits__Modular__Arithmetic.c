#include <stdio.h>
#include <stdint.h>
int main(void)
{
	uint64_t a, b, n, x;
	while (scanf("%llu%llu%llu", &a, &b, &n) == 3)
	{
		x = 0;
		for (a %= n, b %= n; b != 0; b /= 2, a *= 2, a = (a >= n ? a - n : a))
		{
			if (b % 2 == 1)
			{
				x += a;
				if (x >= n)
				{
					x -= n;
				}
			}
		}
		printf("%llu\n", x);
	}
	return 0;
}