#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1024
#define MAX_L 16384
#define MAX_W 10000000
int main(void)
{
	int n;
	scanf("%d", &n);
	char **linePointer[MAX_N];
	int count[MAX_N] = {}, countTotal = 0;
	char *wordPointer[MAX_L];
	char *words = (char *)malloc(MAX_W * sizeof(char));
	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		char space;
		linePointer[i] = &wordPointer[countTotal];
		while (scanf("%s%c", &words[pos], &space) == 2)
		{
			wordPointer[countTotal] = &words[pos];
			countTotal++;
			count[i]++;
			pos += strlen(&words[pos]) + 1;
			if (space == '\n')
			{
				break;
			}
		}
	}
	int m;
	scanf("%d", &m);
	int l1, w1, l2, w2;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d%d", &l1, &w1, &l2, &w2);
		char *tmp = linePointer[l1][w1];
		linePointer[l1][w1] = linePointer[l2][w2];
		linePointer[l2][w2] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			if (j == 0)
			{
				printf("%s", linePointer[i][j]);
			}
			else
			{
				printf(" %s", linePointer[i][j]);
			}
		}
		puts("");
	}
	free(words);
	return 0;
}