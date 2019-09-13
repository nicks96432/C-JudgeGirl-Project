#include <stdio.h>
int main(void)
{
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d\n%d", 2 * (a * b + b * c + c * a) + (a + b + c - 6 * e) * d * 8, a * b * c - 2 * ((a - 2 * e) * (b - 2 * e) * d + (b - 2 * e) * (c - 2 * e) * d + (c - 2 * e) * (a - 2 * e) * d));
	return 0;
}
