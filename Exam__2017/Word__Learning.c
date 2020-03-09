#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Sequence
{
	char type[3];
	int count;
	bool used;
} sequence;
static int comp(const void *x, const void *y)
{
	sequence *a = (sequence *)x, *b = (sequence *)y;
	if (a->count > b->count)
	{
		return -1;
	}
	if (a->count < b->count)
	{
		return 1;
	}
	else
	{
		return strcmp(a->type, b->type);
	}
}
int main(void)
{
	int threshold;
	scanf("%d", &threshold);
	int training[26][26] = {0};
	char word[100];
	while (scanf("%s", word) != EOF)
	{
		const int len = strlen(word);
		for (int i = 0; i < len - 1; i++)
		{
			training[word[i] - 'a'][word[i + 1] - 'a']++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			printf("%d%c", training[i][j], (j == 25 ? '\n' : ' '));
		}
	}
	sequence sequences[26 * 25];
	int countSequence = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (training[i][j] > threshold && (i != j))
			{
				sequences[countSequence].count = training[i][j];
				sequences[countSequence].type[0] = 'a' + i;
				sequences[countSequence].type[1] = 'a' + j;
				sequences[countSequence].type[2] = '\0';
				sequences[countSequence].used = false;
				countSequence++;
			}
		}
	}
	qsort(sequences, countSequence, sizeof(sequence), comp);
#ifdef DEBUG
	for (int i = 0; i < countSequence; i++)
	{
		printf("%s %d\n", sequences[i].type, sequences[i].count);
	}
#endif
	char ans[30] = {};
	strcpy(ans, sequences[0].type);
	bool used[26] = {false};
	bool stop = false;
	sequences[0].used = true;
	used[ans[0] - 'a'] = true;
	used[ans[1] - 'a'] = true;
	while (!stop)
	{
		stop = true;
		const int ansLen = strlen(ans);
		for (int i = 0; i < countSequence; i++)
		{
			if (!(sequences[i].used) && sequences[i].type[0] == ans[ansLen - 1] &&
				!(used[sequences[i].type[1] - 'a']))
			{
				sequences[i].used = true;
				used[sequences[i].type[1] - 'a'] = true;
				ans[ansLen] = sequences[i].type[1];
				stop = false;
				break;
			}
		}
	}
	puts(ans);
	return 0;
}