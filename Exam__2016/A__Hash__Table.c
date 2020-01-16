#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 10000
#define MAX_LEN 100
typedef struct _Bucket
{
	int count;
	char value[MAX_N][MAX_LEN];
} Bucket;
int hash(char *string, int s)
{
	int sum = 0;
	int len = strlen(string);
	for (int i = 0; i < len; i++)
	{
		if (isdigit(string[i]))
		{
			sum += string[i] - '0';
		}
		else
		{
			sum += string[i];
		}
	}
	return (sum % s);
}
int main(void)
{
	int s, n, q;
	scanf("%d%d%d", &s, &n, &q);
	Bucket *hashtable[s];
	for (int i = 0; i < s; i++)
	{
		hashtable[i] = (Bucket *)malloc(sizeof(Bucket));
	}
	int key;
	char string[MAX_LEN];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", string);
		key = hash(string, s);
		strcpy(hashtable[key]->value[hashtable[key]->count], string);
		hashtable[key]->count++;
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%s", string);
		key = hash(string, s);
		bool found = false;
		for (int j = 0; j < hashtable[key]->count; j++)
		{
			if (!strcmp(hashtable[key]->value[j], string))
			{
				printf("%d\n", key);
				found = true;
				break;
			}
		}
		if (!found)
		{
			printf("-1\n");
		}
	}
	for (int i = 0; i < s; i++)
	{
		free(hashtable[i]);
	}
	return 0;
}