#include <stdio.h>
#define PI 3.1415926
int main(void)
{
	double a, b, c, ans;
	scanf("%lf%lf%lf", &a, &b, &c);
	ans = c * c * PI * 3 / 4;
	if (c > b)
	{
		ans += (c - b) * (c - b) * PI / 4;
	}
	if (c > a)
	{
		ans += (c - a) * (c - a) * PI / 4;
	}
	printf("%lf", ans);
	return 0;
}