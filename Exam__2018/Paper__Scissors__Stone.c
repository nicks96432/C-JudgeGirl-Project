#include <stdio.h>
enum hand
{
	PAPER,
	SCISSORS,
	STONE
};
int main(void)
{
	int a, b, c, d, e, f, k = 0, w, N, i, x, y;
	scanf("%d%d%d%d%d%d%d%d%d", &x, &a, &b, &c, &y, &d, &e, &f, &N);
	for (i = 0; i < N; i++)
	{
		k = 1;
		while (x % 3 == y % 3)
		{
			x = (a * x + b) % c;
			y = (d * y + e) % f;
			k++;
		}
		if ((x % 3 == PAPER && y % 3 == STONE) || (x % 3 == STONE && y % 3 == SCISSORS) || (x % 3 == SCISSORS && y % 3 == PAPER))
		{
			w = 0;
		}
		else
		{
			w = 1;
		}
		printf("%d %d\n", w, k);
		x = (a * x + b) % c;
		y = (d * y + e) % f;
	}
	return 0;
}