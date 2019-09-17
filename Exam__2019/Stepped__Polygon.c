#include <stdio.h>
int main(void)
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	int perimeter = (a + b + c + d + e + f) * 2;
	int area = (a + c + e) * (b + d + f) - b * (c + e) - d * e;
	printf("%d\n%d", perimeter, area);
	return 0;
}