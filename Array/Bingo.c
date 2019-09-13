#include <stdio.h>
#ifdef DEBUG
#include <time.h>
#endif //DEBUG
int main(void)
{
#ifdef DEBUG
	clock_t begin, end;
#endif //DEBUG
	int n, m, i, j, k, l;
	scanf("%d%d", &n, &m);
	int column[n][m], row[n][m], left__diagonal[n], right__diagonal[n];
	char name[n][65];
	unsigned int bingo__card[n][m * m + 1][2], tmp = 0;
	_Bool who__bingo[n], Bingo = 0;
	for (i = 0; i < n; i++)
	{
		*(who__bingo + i) = 0;
		scanf("%s", name[i]);
		left__diagonal[i] = 0;
		right__diagonal[i] = 0;
		for (j = 0; j < m; j++)
		{
			column[i][j] = 0;
			row[i][j] = 0;
			for (k = 0; k < m; k++)
			{
				scanf("%d", &tmp);
				bingo__card[i][tmp][0] = k;
				bingo__card[i][tmp][1] = j;
			}
		}
	}
#ifdef DEBUG
	begin = clock();
#endif //DEBUG
	while (scanf("%d", &tmp) == 1)
	{
		for (j = 0; j < n; j++)
		{
			column[j][bingo__card[j][tmp][1]]++;
			row[j][bingo__card[j][tmp][0]]++;
			if (bingo__card[j][tmp][0] == bingo__card[j][tmp][1])
			{
				left__diagonal[j]++;
			}
			if (bingo__card[j][tmp][0] + bingo__card[j][tmp][1] == m - 1)
			{
				right__diagonal[j]++;
			}
			if (column[j][bingo__card[j][tmp][1]] == m || row[j][bingo__card[j][tmp][0]] == m || left__diagonal[j] == m || right__diagonal[j] == m)
			{
				who__bingo[j] = 1;
				Bingo = 1;
			}
		}
		if (Bingo)
		{
			break;
		}
	}
#ifdef DEBUG
	end = clock();
	printf("%lf\n", (double)(end - begin) / CLOCKS_PER_SEC);
#endif // DEBUG
	printf("%d", tmp);
	i = 0;
	for (j = 0; j < n; j++)
	{
		i += who__bingo[j];
	}
	for (j = 0; j < n; j++)
	{
		if (*(who__bingo + j) == 1)
		{
			printf(" %s", *(name + j));
		}
	}
	return 0;
}