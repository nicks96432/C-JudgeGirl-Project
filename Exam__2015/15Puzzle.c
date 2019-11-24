#include <stdio.h>
static const int directions[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
static int board[4][4] = {}, solved = 0;
static int k;
static void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
static int issolved(void)
{
	int i, j, k = 1;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[i][j] != (k % 16))
			{
				return 0;
			}
			k++;
		}
	}
	return 1;
}
static void solve(int step, int nextblankx, int nextblanky)
{
	if (issolved())
	{
		solved = 1;
		return;
	}
	if (step == k)
	{
		return;
	}
	if (step + (3 - nextblankx) + (3 - nextblanky) > k)
	{
		return;
	}
	int i, tmpx, tmpy;
	for (i = 0; i < 4; i++)
	{
		tmpx = nextblankx + directions[i][0];
		tmpy = nextblanky + directions[i][1];
		if (tmpx < 0 || tmpy < 0 || tmpx >= 4 || tmpy >= 4)
		{
			continue;
		}
		swap(&board[nextblankx][nextblanky], &board[tmpx][tmpy]);
		solve(step + 1, tmpx, tmpy);
		swap(&board[nextblankx][nextblanky], &board[tmpx][tmpy]);
	}
	return;
}
int main(void)
{
	int i, j;
	int blankx, blanky;
	while (scanf("%d", &k) != EOF)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				scanf("%d", &board[i][j]);
				if (board[i][j] == 0)
				{
					blankx = i;
					blanky = j;
				}
			}
		}
		solved = 0;
		solve(0, blankx, blanky);
		printf("%d\n", solved);
	}
	return 0;
}