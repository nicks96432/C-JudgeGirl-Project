#include <stdio.h>
#include <string.h>
#include "splitAndMap.h"
void splitAndMap(char ***ptr, char *str)
{
	int i, j;
	for (i = 0; ptr[i] != NULL; i++)
	{
		continue;
	}
	const int n = i;
	int count[10]={}, count__words[10]={}, min, min__index;
	char *tmp = str;
	char *delim = "*";
	tmp = strtok(str, delim);
	while (tmp != NULL)
	{
		min = 2147483647;
		for (i = 0; i < n; i++)
		{
			if (count__words[i] < min)
			{
				min = count__words[i];
				min__index = i;
			}
		}
		ptr[min__index][count[min__index]] = tmp;
		count__words[min__index] += strlen(tmp);
		count[min__index]++;
		tmp = strtok(NULL, delim);
	}
	for (i = 0; i < n; i++)
	{
		ptr[i][count[i]] = NULL;
	}
	return;
}