#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 35
#define MAX_STRINGS 65
int comp(const void *x, const void *y)
{
	return strcmp((char *)x, (char *)y);
}
int main(void)
{
	int countStrings = 0;
	char strings[MAX_STRINGS][MAX_LEN];
	while (fgets(strings[countStrings], 35, stdin) != NULL)
	{
		countStrings++;
	}
	qsort(strings, countStrings, sizeof(strings[0]), comp);
	for (int i = 0; i < countStrings; i++)
	{
		printf("%s", strings[i]);
	}
	return 0;
}