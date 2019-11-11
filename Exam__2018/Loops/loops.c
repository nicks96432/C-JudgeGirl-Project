#include <stdio.h>
void loops(int N, int *A, int *B[], int ans[4])
{
	int i, visited[N], count = 0, count__visited = 0, next = 0;
	for (i = 0; i < N; i++)
	{
		visited[i] = 0;
	}
	int tmp__min = 2147483647, tmp__max = -2147483647;
	ans[0] = -2147483647;
	ans[1] = 2147483647;
	ans[2] = -2147483647;
	ans[3] = 2147483647;
	while (count__visited < N)
	{
		if (visited[next] == 0)
		{
			visited[next] = 1;
			count__visited++;
			count++;
			if (A[next] > tmp__max)
			{
				tmp__max = A[next];
			}
			if (A[next] < tmp__min)
			{
				tmp__min = A[next];
			}
		}
		else
		{
			if (count >= ans[0])
			{
				if (count > ans[0])
				{
					ans[2] = -2147483647;
				}
				ans[0] = count;
				if (tmp__max > ans[2])
				{
					ans[2] = tmp__max;
				}
			}
			if (count <= ans[1])
			{
				if (count < ans[1])
				{
					ans[3] = 2147483647;
				}
				ans[1] = count;
				if (tmp__min < ans[3])
				{
					ans[3] = tmp__min;
				}
			}
			if (count__visited != N)
			{
				count = 0;
				tmp__max = -2147483647;
				tmp__min = 2147483647;
			}
			for (i = 0; i < N; i++)
			{
				if (visited[i] == 0)
				{
					next = i;
					break;
				}
			}
			continue;
		}
		next = B[next] - A;
	}
	if (count >= ans[0])
	{
		if (count > ans[0])
		{
			ans[2] = -2147483647;
		}
		ans[0] = count;
		if (tmp__max > ans[2])
		{
			ans[2] = tmp__max;
		}
	}
	if (count <= ans[1])
	{
		if (count < ans[1])
		{
			ans[3] = 2147483647;
		}
		ans[1] = count;
		if (tmp__min < ans[3])
		{
			ans[3] = tmp__min;
		}
	}
	return;
}