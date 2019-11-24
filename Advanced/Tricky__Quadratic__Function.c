#include <stdio.h>
#include <math.h>
void swap(double *a, double *b)
{
	double tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
int main(void)
{
	double a, b, c, ans1, ans2;
	while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
	{
		ans1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		ans2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		if (isgreater(ans1, ans2))
		{
			swap(&ans1, &ans2);
		}
		printf("%.20lf %.20lf\n", ans1, ans2);
	}
	return 0;
}