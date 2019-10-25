#include <stdio.h>
#include "findLength.h"
#define MAX 256
int main(void)
{
	int array[MAX][MAX], N;
	scanf("%d", &N);
	int direction[4][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}};
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	int ans = -1, tmp;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 4; j++)
		{
			tmp = findLength(array, N, i, 0, direction[j][0], direction[j][1]);
			ans = ans > tmp ? ans : tmp;
			tmp = findLength(array, N, 0, i, direction[j][0], direction[j][1]);
			ans = ans > tmp ? ans : tmp;
			tmp = findLength(array, N, N-1, i, direction[j][0], direction[j][1]);
			ans = ans > tmp ? ans : tmp;
		}
	}
	printf("%d", ans);
	return 0;
}