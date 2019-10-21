#include <stdio.h>
int matrix(int, int);
int main(void)
{
	int r, c;
	scanf("%d%d", &r, &c);
	printf("%d", matrix(r, c));
}
int matrix(int r, int c)
{
	if (r == 1)
	{
		return 1;
	}
	if (c == 1)
	{
		return 1;
	}
	return matrix(r - 1, c) + matrix(r, c - 1);
}