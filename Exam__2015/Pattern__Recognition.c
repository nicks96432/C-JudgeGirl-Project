#include <stdio.h>
#define abs(x) ((x) > 0 ? (x) : (-(x)))
int main(void)
{
	int N, K, m, d;
	scanf("%d%d%d%d", &N, &K, &m, &d);
	int i, j, k, l;
	int matrix[N][N], submatrix[K][K], sum__submatrix = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	for (i = 0; i < K; i++)
	{
		for (j = 0; j < K; j++)
		{
			scanf("%d", &submatrix[i][j]);
			sum__submatrix += submatrix[i][j];
		}
	}
	int column = -1, row = -1, count, sum = 0;
	for (i = 0; i <= N - K; i++)
	{
		for (j = 0; j <= N - K; j++)
		{
			sum = 0;
			count = 0;
			for (k = i; k < i + K; k++)
			{
				for (l = j; l < j + K; l++)
				{
					sum += matrix[k][l];
					if (matrix[k][l] != submatrix[k - i][l - j])
					{
						count++;
					}
				}
			}
			if (count <= m && abs(sum - sum__submatrix) <= d && (i > column || (i == column && j > row)))
			{
				column = i;
				row = j;
			}
		}
	}
	printf("%d %d", column, row);
	return 0;
}