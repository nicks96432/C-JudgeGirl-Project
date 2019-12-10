#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 500
char subset[240000][MAX_LEN];
int comp(const void *x, const void *y)
{
	return strcmp((char *)x, (char *)y);
}
int main(void)
{
	char s[MAX_LEN];
	scanf("%s", s);
	int len = strlen(s);
	int i, j;
	int count = 0;
	for (i = 0; i < len; i++)
	{
		for (j = 1; j <= len - i; j++)
		{
			strncpy(subset[count], s + i, j);
			count++;
		}
	}
	qsort((void *)subset, count, sizeof(subset[0]), comp);
	printf("%s\n", subset[0]);
	for (i = 1; i < count; i++)
	{
		if (strcmp(subset[i - 1], subset[i]))
		{
			printf("%s\n", subset[i]);
		}
	}
	return 0;
}