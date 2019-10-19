#include <stdio.h>
#include <string.h>
#define abs(x) ((x) > 0 ? (x) : (-(x)))
void swap(int *, int *);
int main(void)
{
	int puzzle[6][6], i, j, n;
	int position[16][2];
	int count = 0;
	memset(puzzle, -1, sizeof(int) * 36);
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			scanf("%d", &puzzle[i][j]);
			position[puzzle[i][j]][0] = i;
			position[puzzle[i][j]][1] = j;
		}
	}
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		if ((abs(position[0][0] - position[n][0]) == 1 && position[0][1] == position[n][1]) || (abs(position[0][1] - position[n][1]) == 1 && position[0][0] == position[n][0]))
		{
			swap(&puzzle[position[0][0]][position[0][1]], &puzzle[position[n][0]][position[n][1]]);
			swap(&position[0][0], &position[n][0]);
			swap(&position[0][1], &position[n][1]);
		}
		count = 0;
		for (i = 1; i <= 4; i++)
		{
			for (j = 1; j <= 4; j++)
			{
				if (puzzle[i][j] == ((i - 1) * 4 + j) % 16)
				{
					count++;
				}
			}
		}
		if (count == 16)
		{
			for (i = 1; i <= 4; i++)
			{
				for (j = 1; j < 4; j++)
				{
					printf("%d ", puzzle[i][j]);
				}
				printf("%d\n", puzzle[i][j]);
			}
			printf("1 %d", n);
			return 0;
		}
	}
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j < 4; j++)
		{
			printf("%d ", puzzle[i][j]);
		}
		printf("%d\n", puzzle[i][j]);
	}
	printf("0");
	return 0;
}
void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}