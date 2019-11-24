#include <stdio.h>
#include <string.h>
#define MAX_N 100002
static int numbers[MAX_N] = {};
int main(void)
{
	int i, n, num;
	while (scanf("%d", &n) != EOF)
	{
		memset(numbers, 0, sizeof(numbers));
		for (i = 0; i < n; i++)
		{
			scanf("%d", &num);
			numbers[num]++;
		}
		for (i = 1; i < n; i++)
		{
			if (numbers[i] >= 2)
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}