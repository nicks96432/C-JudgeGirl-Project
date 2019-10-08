#include <stdio.h>
#include <stdbool.h>
int da, db, dc, ea, eb, ec, fa, fb, fc;
bool composite(int, int, int);
void input(int, int[], int[], int[]);
int main(void)
{
	int n;
	scanf("%d%d%d%d%d%d%d%d%d", &da, &db, &dc, &ea, &eb, &ec, &fa, &fb, &fc);
	scanf("%d", &n);
	int a[n], b[n], c[n];
	input(n, a, b, c);
	return 0;
}
bool composite(int a, int b, int c)
{
	if (a == 0 && b == 0 && c == 0)
	{
		return true;
	}
	if (a < 0 || b < 0 || c < 0)
	{
		return false;
	}
	return composite(a - da, b - db, c - dc) || composite(a - ea, b - eb, c - ec) || composite(a - fa, b - fb, c - fc);
}
void input(int n, int a[], int b[], int c[])
{
	if (n == 0)
	{
		return;
	}
	scanf("%d%d%d", &a[n - 1], &b[n - 1], &c[n - 1]);
	if (composite(a[n - 1], b[n - 1], c[n - 1]))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	input(n - 1, a, b, c);
}