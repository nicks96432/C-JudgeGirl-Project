#include <stdio.h>
#include <math.h>
int main()
{
	long long int a, b, c;
	int i, j;
	double A, B, C, x1, x2, x3, t, theta, ans[3], tmp;
	scanf("%lld %lld %lld", &a, &b, &c);
	A = a * a - 3 * b;
	B = a * b - 9 * c;
	C = b * b - 3 * a * c;
	if (A == B && B == 0)
	{
		x1 = -a / 3;
		x2 = x1;
		x3 = x1;
	}
	else if ((B * B - 4 * A * C) == 0)
	{
		x1 = -a + B / A;
		x2 = -B / (2 * A);
		x3 = x2;
	}
	else
	{
		t = (2 * A * a - 3 * B) / (2 * A * sqrt(A));
		theta = acos(t);
		x1 = (-a - 2 * sqrt(A) * cos(theta / 3)) / 3;
		x2 = (-a + sqrt(A) * (cos(theta / 3) + sqrt(3) * sin(theta / 3))) / 3;
		x3 = (-a + sqrt(A) * (cos(theta / 3) - sqrt(3) * sin(theta / 3))) / 3;
	}
	ans[0] = round(-x1);
	ans[1] = round(-x2);
	ans[2] = round(-x3);
	for (i = 0; i < 3; i++)
	{
		for (j = i; j < 3; j++)
		{
			if (ans[i] >= ans[j])
			{
				tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}
	}
	printf("%d %d %d", (int)ans[0], (int)ans[1], (int)ans[2]);
	return 0;
}