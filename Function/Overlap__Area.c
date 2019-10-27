#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
long int area(const long int a[4]);
void overlap(long int a[4], const long int b[4], const long int c[4]);
int main(void)
{
	int i, j;
	long int ans;
	// 0:左下x 1:左下y 2:右上x 3:右上y
	long int rectangle[3][4];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%ld", &rectangle[i][j]);
		}
	}
	long int abpoint[4], bcpoint[4], capoint[4], abcpoint[4];
	overlap(abpoint, rectangle[0], rectangle[1]);
	overlap(bcpoint, rectangle[1], rectangle[2]);
	overlap(capoint, rectangle[2], rectangle[0]);
	overlap(abcpoint, abpoint, rectangle[2]);
	ans = area(rectangle[0]) + area(rectangle[1]) + area(rectangle[2]) - area(abpoint) - area(bcpoint) - area(capoint) + area(abcpoint);
	printf("%ld", ans);
	return 0;
}
void overlap(long int a[4], const long int b[4], const long int c[4])
{

	// 0:長 1:寬
	if ((b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0) || (c[0] == 0 && c[1] == 0 && c[2] == 0 && c[3] == 0))
	{
		a[0] = 0;
		a[1] = 0;
		a[2] = 0;
		a[3] = 0;
		return;
	}
	a[0] = max(b[0], c[0]);
	a[1] = max(b[1], c[1]);
	a[2] = min(b[2], c[2]);
	a[3] = min(b[3], c[3]);
	if (a[2] - a[0] <= 0 || a[3] - a[1] <= 0)
	{
		a[0] = 0;
		a[1] = 0;
		a[2] = 0;
		a[3] = 0;
	}
	return;
}
long int area(const long int a[4])
{
	return (a[2] - a[0]) * (a[3] - a[1]);
}