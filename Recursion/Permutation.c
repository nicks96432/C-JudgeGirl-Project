#include <stdio.h>
#include <stdlib.h>
int n, num[10] = {0}, ans[10] = {0}, used[10] = {0};
void perm(int);
int comp(const void *a, const void *b)
{
	return *(int *)a > *(int *)b;
}
int main(void)
{
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	qsort(num, n, sizeof(num[0]), comp);
	perm(0);
	return 0;
}
void perm(int count)
{
	int i;
	if (count == n)
	{
		for (i = 0; i < n - 1; i++)
		{
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[i]);
		return;
	}
	for (i = 0; i < n; i++)
	{
		if (used[i])
		{
			continue;
		}
		used[i] = 1;
		ans[count] = num[i];
		perm(count + 1);
		used[i] = 0;
	}
}