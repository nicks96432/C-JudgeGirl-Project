#include <stdio.h>
#include <string.h>
#define MAX_WORDS 100
#define MAX_LENGTH 15
#define min(x, y) ((x) < (y) ? (x) : (y))
int distance(char *, char *, int, int);
int main(void)
{
	int i = 0, j, tmp;
	int shortest = 2147483647, id1, id2;
	char strings[MAX_WORDS][MAX_LENGTH];
	while (scanf("%s", strings[i]) != EOF)
	{
		i++;
	}
	const int words = i;
	for (i = 0; i < words; i++)
	{
		for (j = i + 1; j < words; j++)
		{
			tmp = distance(strings[i], strings[j], shortest, 0);
			if (tmp < shortest || (tmp == shortest && i * 1000 + j < id1 * 1000 + id2))
			{
				shortest = tmp;
				id1 = i;
				id2 = j;
			}
		}
	}
	printf("%d %d %d\n", shortest, id1 + 1, id2 + 1);
	return 0;
}
int distance(char *word1, char *word2, int shortest, int now)
{
	int ans = 2147483647, tmp;
	if (now > shortest)
	{
		return 2147483647;
	}
	if (*word1 == '\0' && *word2 == '\0')
	{
		return now;
	}
	if (*word1 == *word2)
	{
		tmp = distance(word1 + 1, word2 + 1, shortest, now);
		ans = min(tmp, ans);
	}
	if (*word1 != '\0')
	{
		tmp = distance(word1 + 1, word2, shortest, now + 1);
		ans = min(tmp, ans);
	}
	if (*word2 != '\0')
	{
		tmp = distance(word1, word2 + 1, shortest, now + 1);
		ans = min(tmp, ans);
	}
	return ans;
}