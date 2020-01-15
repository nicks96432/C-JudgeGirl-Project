#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 30
bool onlyAlnum(char plate[8], int type)
{
	for (int i = 0; i < 7; i++)
	{
		if (i != type + 1 && !isalnum(plate[i]))
		{
			return false;
		}
	}
	return true;
}
bool checkDigit(char plate[8])
{
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{
		if (isdigit(plate[i]))
		{
			sum += plate[i] - '0';
		}
	}
	return sum % 7 ? true : false;
}
bool checkSame(char plate[8], int type)
{
	for (int i = 0; i < 7; i++)
	{
		if (i == type + 1)
		{
			continue;
		}
		int count = 0;
		for (int j = 0; j < 7; j++)
		{
			if (plate[i] == plate[j])
			{
				count++;
			}
		}
		if (count > 2)
		{
			return false;
		}
	}
	return true;
}
bool check4(char plate[8])
{
	for (int i = 0; i < 6; i++)
	{
		if (plate[i] == '4' && plate[i + 1] == '4')
		{
			return false;
		}
	}
	return true;
}
bool test(char plate[8])
{
	if (plate[2] != '-' && plate[3] != '-')
	{
		return false;
	}
	if (plate[2] == '-')
	{
		if (!onlyAlnum(plate, 1) || !checkDigit(plate) ||
			!checkSame(plate, 1) || !check4(plate))
		{
			return false;
		}
	}
	else if (plate[3] == '-')
	{
		if (!onlyAlnum(plate, 2) || !checkDigit(plate) ||
			!checkSame(plate, 2) || !check4(plate))
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}
int comp(const void *x, const void *y)
{
	return strcmp((char *)x, (char *)y);
}
int main(void)
{
	int n;
	char first[MAX_N][8], second[MAX_N][8];
	int countFirst = 0, countSecond = 0;
	scanf("%d", &n);
	char plate[8];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", plate);
		if (test(plate))
		{
			if (plate[2] == '-')
			{
				strcpy(first[countFirst], plate);
				countFirst++;
			}
			else
			{
				strcpy(second[countSecond], plate);
				countSecond++;
			}
		}
	}
	qsort(first, countFirst, sizeof(char *), comp);
	qsort(second, countSecond, sizeof(char *), comp);
	for (int i = 0; i < countFirst; i++)
	{
		puts(first[i]);
	}
	for (int i = 0; i < countSecond; i++)
	{
		puts(second[i]);
	}
	return 0;
}