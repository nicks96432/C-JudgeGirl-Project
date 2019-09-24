#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int i = 0, j, k, n, count__word = 0, word__len[200000], space, count__len, count__tmp, extra__space;
	char *word[655360], *tmp[10000];
	for (i = 0; i < 655360; i++)
	{
		word[i] = malloc(256 * sizeof(char));
	}
	for (i = 0; i < 10000; i++)
	{
		tmp[i] = malloc(256 * sizeof(char));
	}
	i = 0;
	scanf("%d", &n);
	while (scanf("%s", word[i]) != EOF)
	{
		word__len[i] = strlen(word[i]);
		i++;
		count__word++;
	}
#ifdef DEBUG
	for (i = 0; i < count__word; i++)
	{
		printf("%s ", word[i]);
	}
#endif
	for (i = 0; i < count__word;)
	{
		for (j = 0; j < 10000; j++)
		{
			memset(tmp[j], '\0', 256 * sizeof(char));
		}
		count__tmp = 0;
		count__len = 0;
		while (count__len < n - count__tmp - 1)
		{
			strcpy(tmp[count__tmp], word[i]);
			count__len += word__len[i];
			if (count__len > n - count__tmp)
			{
				count__len -= word__len[i];
				break;
			}
			i++;
			count__tmp++;
			if (i == count__word)
			{
				break;
			}
		}
		if (count__tmp > 1)
		{
			space = (n - count__len) / (count__tmp - 1);
			extra__space = (n - count__len) % (count__tmp - 1);
		}
		else
		{
			space = n - count__len;
			extra__space = 0;
		}

		for (j = 0; j < extra__space; j++)
		{
			printf("%s", tmp[j]);
			for (k = 0; k < space + 1; k++)
			{
				printf(" ");
			}
		}
		for (; j < count__tmp - 1; j++)
		{
			printf("%s", tmp[j]);
			for (k = 0; k < space; k++)
			{
				printf(" ");
			}
		}
		printf("%s", tmp[j]);
		printf("\n");
	}
	for (i = 0; i < 200000; i++)
	{
		free(word[i]);
	}
	for (i = 0; i < 10000; i++)
	{
		free(tmp[i]);
	}
	return 0;
}