#include <stdio.h>
int main(void)
{
	int a, b, c, d, e, f, g, edges, paths;
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
	// printf("%d %d %d %d %d %d %d", a, b, c, d, e, f, g);
	edges = a + b + c + d + a * e + b * e + c * e + c * f + d * f + e * g + f + g;
	paths = (a + b + c) * e * g + (c + d) * f;
	printf("%d\n%d", edges, paths);
	return 0;
}