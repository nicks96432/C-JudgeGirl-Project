#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define TMPMAX 500
void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks)
{
	int i, j;
	*numberOfBlocks = 0;
	for (i = 0;; i++)
	{
		if (ptrArray[i] == NULL && ptrArray[i + 1] == NULL)
		{
			break;
		}
	}
	int arr__max = i + 1;
	for (i = 0; i < arr__max; i++)
	{
		if (ptrArray[i] == NULL)
		{
			(*numberOfBlocks)++;
		}
	}
	int counttmp = 0, countans = 0;
	const int *tmpptr[TMPMAX];
	bool exist = false;
	memset(tmpptr, 0, sizeof(tmpptr[0]) * TMPMAX);
	for (i = 0; i < arr__max; i++)
	{
		if (ptrArray[i] == NULL)
		{
			for (j = 0; j < counttmp; j++)
			{
				answer[countans] += *tmpptr[j];
			}
			memset(tmpptr, 0, sizeof(tmpptr[0]) * TMPMAX);
			counttmp = 0;
			countans++;
		}
		else
		{
			exist = false;
			for (j = 0; j < counttmp; j++)
			{
				if (ptrArray[i] == tmpptr[j])
				{
					exist = true;
					break;
				}
			}
			if (exist)
			{
				continue;
			}
			else
			{
				tmpptr[counttmp] = ptrArray[i];
				counttmp++;
			}
		}
	}
	return;
}