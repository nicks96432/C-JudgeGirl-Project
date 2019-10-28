#include <stdio.h>
#define MAX__DEGREE 10
double power(double, int);
int main(void)
{
	int degree, i, j;
	scanf("%d", &degree);
	double coefficient[MAX__DEGREE + 1] = {};
	for (i = degree; i >= 0; i--)
	{
		scanf("%lf", &coefficient[i]);
	}
	int iteration;
	scanf("%d", &iteration);
	double x1, x, fx, fprimex;
	scanf("%lf", &x1);
	double derivative[MAX__DEGREE] = {};
	for (i = 0; i < degree; i++)
	{
		derivative[i] = coefficient[i + 1] * (i + 1);
	}
	for (i = 0; i < iteration; i++)
	{
		fx = 0;
		fprimex = 0;
		for (j = 0; j <= degree; j++)
		{
			fx += power(x1, j) * coefficient[j];
			if (j <= degree - 1)
			{
				fprimex += power(x1, j) * derivative[j];
			}
		}
		printf("%.4lf %.4lf\n", x1, fx);
		x = x1 - fx / fprimex;
		x1 = x;
	}
	return 0;
}
double power(double x, int i)
{
	double tmp = x;
	x = 1;
	for (; i > 0; i--)
	{
		x *= tmp;
	}
	return x;
}