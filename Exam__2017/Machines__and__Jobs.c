#pragma GCC optimize("Ofast")
#pragma GCC target("sse3", "sse2", "sse")
#pragma GCC target("avx", "sse4", "sse4.1", "sse4.2", "ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
#include <stdio.h>
#define INT_MAX 2147483647
#define MAX_MACHINE 512
#define MAX_JOBS 512
#define MAX_SUBTASK 512
#define max(x, y) ((x) > (y) ? (x) : (y))
typedef struct Subtask
{
	int machine;
	int cost;
} subtask;
int machine__ready[MAX_MACHINE] = {0};
int arrive__time[MAX_JOBS] = {0};
int finish__time[MAX_JOBS] = {0};
int subtasks[MAX_JOBS] = {0};
int processed__subtasks[MAX_JOBS] = {0};
subtask subtask__list[MAX_JOBS][MAX_SUBTASK];
int main(void)
{
	int n, m;
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &arrive__time[i], &subtasks[i]);
		for (j = 0; j < subtasks[i]; j++)
		{
			scanf("%d%d", &subtask__list[i][j].machine, &subtask__list[i][j].cost);
		}
	}
	int finish = 0;
	int timecost, min__timecost, min__timecost__index;
	while (finish != m)
	{
		min__timecost = INT_MAX;
		for (i = 0; i < m; i++)
		{
			if (processed__subtasks[i] == subtasks[i])
			{
				continue;
			}
			else
			{
				timecost = max(machine__ready[subtask__list[i][processed__subtasks[i]].machine], arrive__time[i]) + subtask__list[i][processed__subtasks[i]].cost;
			}
			if (timecost < min__timecost)
			{
				min__timecost = timecost;
				min__timecost__index = i;
			}
		}
		machine__ready[subtask__list[min__timecost__index][processed__subtasks[min__timecost__index]].machine] = min__timecost;
		arrive__time[min__timecost__index] = min__timecost;
		processed__subtasks[min__timecost__index]++;
		if (processed__subtasks[min__timecost__index] == subtasks[min__timecost__index])
		{
			finish__time[min__timecost__index] = min__timecost;
			finish++;
		}
	}
	for (i = 0; i < m; i++)
	{
		printf("%d\n", finish__time[i]);
	}
	return 0;
}