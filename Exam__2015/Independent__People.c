#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100
bool find(int n, int m, bool friendship[][MAX_N], int answer[], int available[], int count)
{
	if (count == m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d%c", answer[i], i == m - 1 ? '\n' : ' ');
		}
		return true;
	}
	if (count + n < m)
	{
		return false;
	}
	if (n == 0)
	{
		return false;
	}
	/* 如果要加入新的人，要建一個新表 */
	int next[MAX_N], countnext = 0;
	for (int i = 1; i < n; i++)
	{
		if (friendship[available[i]][available[0]] == false)
		{
			next[countnext] = available[i];
			countnext++;
		}
	}
	answer[count] = available[0];
	/* 選或不選 */
	return find(countnext, m, friendship, answer, next, count + 1) ||
		   find(n - 1, m, friendship, answer, available + 1, count);
}
int main(void)
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		int tmp;
		int answer[MAX_N] = {};
		bool friendship[MAX_N][MAX_N];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &tmp);
				friendship[i][j] = tmp ? true : false;
			}
		}
		int available[MAX_N];
		for (int i = 0; i < n; i++)
		{
			available[i] = i;
		}
		if (!find(n, m, friendship, answer, available, 0))
		{
			puts("no solution");
		}
	}
	return 0;
}