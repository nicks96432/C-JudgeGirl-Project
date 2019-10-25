#include <stdio.h>
#include <math.h>
void find__point(double a1, double b1, double c1, double a2, double b2, double c2, double *x, double *y)
{
	c1 = -c1;
	c2 = -c2;
	*x = (c1 * b2 - b1 * c2) / (a1 * b2 - b1 * a2);
	*y = (a1 * c2 - c1 * a2) / (a1 * b2 - b1 * a2);
	return;
}
double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main(void)
{
	int n;
	int i;
	double delta, delta__x, delta__y;
	double ans = 0;
	scanf("%d", &n);
	double a[n], b[n], c[n];
	double x[n], y[n];
	for (i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		find__point(a[i], b[i], c[i], a[i + 1], b[i + 1], c[i + 1], &x[i], &y[i]);
	}
	find__point(a[0], b[0], c[0], a[i], b[i], c[i], &x[i], &y[i]);
	for (i = 0; i < n - 1; i++)
	{
		ans += distance(x[i], y[i], x[i + 1], y[i + 1]);
	}
	ans += distance(x[i], y[i], x[0], y[0]);
	printf("%.3lf\n", ans);
	return 0;
}