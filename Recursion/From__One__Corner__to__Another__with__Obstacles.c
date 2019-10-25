#include <stdio.h>
int map[13][13] = {};
int matrix(int, int);
int main(void)
{
	int r, c;
	scanf("%d%d", &r, &c);
	int i, j;
	for (i = r - 1; i >= 0; i--)
	{
		for (j = 0; j < c; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d\n", matrix(r - 1, c - 1));
	return 0;
}
int matrix(int r, int c)
{
	if (r < 0 || c < 0 || map[r][c] == 0)
	{
		return 0;
	}
	if (r == 0 && c == 0)
	{
		return 1;
	}
	return matrix(r - 1, c) + matrix(r, c - 1);
}