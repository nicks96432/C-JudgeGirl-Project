#include <stdio.h>
#include <string.h>
int n, minpress = 2147483647, tmp[16] = {0}, ans[16] = {0}, used[16] = {0};
int puzzle[4][4] = {0};
int find1(void)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (puzzle[i][j])
			{
				return 1;
			}
		}
	}
	return 0;
}
void adjust(int i)
{
	puzzle[i / n][i % n] = (puzzle[i / n][i % n] + 1) % 2;
	if (i / n + 1 < n)
	{
		puzzle[i / n + 1][i % n] = (puzzle[i / n + 1][i % n] + 1) % 2;
	}
	if (i / n - 1 >= 0)
	{
		puzzle[i / n - 1][i % n] = (puzzle[i / n - 1][i % n] + 1) % 2;
	}
	if (i % n + 1 < n)
	{
		puzzle[i / n][i % n + 1] = (puzzle[i / n][i % n + 1] + 1) % 2;
	}
	if (i % n - 1 >= 0)
	{
		puzzle[i / n][i % n - 1] = (puzzle[i / n][i % n - 1] + 1) % 2;
	}
	return;
}
void solve(int now, int count)
{
	if (now > n * n)
	{
		return;
	}
	if (count >= minpress)
	{
		return;
	}
	int i;
	if (find1() == 0)
	{
		if (count < minpress)
		{
			minpress = count;
			memset(ans, 0, sizeof(ans));
			for (i = 0; i < minpress; i++)
			{
				ans[i] = tmp[i];
			}
		}
		return;
	}
	for (i = now; i < n * n; i++)
	{
		if (used[i])
		{
			continue;
		}
		tmp[count] = i;
		used[i] = 1;
		adjust(i);
		solve(now + 1, count + 1);
		used[i] = 0;
		adjust(i);
	}
	return;
}
int main(void)
{
	int input;
	scanf("%d", &n);
	while (scanf("%d", &input) != EOF)
	{
		puzzle[input / n][input % n] = 1;
	}
	solve(0, 0);
	int i;
	for (i = 0; i < minpress; i++)
	{
		printf("%d%c", ans[i], i == minpress - 1 ? '\n' : ' ');
	}
	return 0;
}