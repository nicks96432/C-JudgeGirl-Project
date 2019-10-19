#include <stdio.h>
#define abs(x) ((x) > 0 ? (x) : (-(x)))
int main(void)
{
	int a, b, c, d, e;
	int p, q, r, s;
	int x, y, F;
	int last__x = 0, last__y = 0;
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &p, &q, &r, &s, &x, &y, &F);
	int gold = abs(c * x + d * y) % e;
	while (F >= 0)
	{
		switch (abs(a * x + b * y) % 4)
		{
		case 0:
			y++;
			F--;
			break;
		case 1:
			x++;
			F--;
			break;
		case 2:
			y--;
			F--;
			break;
		case 3:
			x--;
			F--;
			break;
		default:
			break;
		}
		if (x == p && y == q)
		{
			x = r;
			y = s;
		}
		else if (x == r && y == s)
		{
			x = p;
			y = q;
		}
		else if (F >= 0)
		{
			gold += abs(c * x + d * y) % e;
		}
		if (F == 0)
		{
			last__x = x;
			last__y = y;
		}
	}
	printf("%d\n%d %d", gold, last__x, last__y);
	return 0;
}