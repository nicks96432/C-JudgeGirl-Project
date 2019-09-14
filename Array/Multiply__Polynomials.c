#include <stdio.h>
int main(void)
{
	int f__size, g__size;
	scanf("%d", &f__size);
	int i, f[f__size];
	for (i = 0; i < f__size; i++)
	{
		scanf("%d", f + i);
	}
	scanf("%d", &g__size);
	int j, g[g__size], ans[f__size + g__size];
	for (i = 0; i < g__size; i++)
	{
		scanf("%d", g + i);
	}
	for (i = 0; i < f__size + g__size; i++)
	{
		ans[i] = 0;
	}
	for (i = 0; i < f__size; i++)
	{
		for (j = 0; j < g__size; j++)
		{
			ans[i + j] += f[i] * g[j];
		}
	}
	for (i = 0; i < f__size + g__size - 2; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("%d", ans[i]);
	return 0;
}