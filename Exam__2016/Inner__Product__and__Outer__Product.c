#include <stdio.h>
int main(void)
{
	int a, b, c;
	int d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	printf("%d\n", a * d + b * e + c * f);
	int g = b * f - c * e, h = c * d - a * f, i = a * e - b * d;
	printf("%d %d %d", g, h, i);
	return 0;
}