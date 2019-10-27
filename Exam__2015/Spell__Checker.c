#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX__DICTIONARY 100000
#define MAX__WORDS 1000
#pragma region "耍懶覺"
#pragma hdrstop
#pragma loop_opt(on)
#pragma message("muy bien 小心ㄐㄐ")
#warning 國際盜懶覺集團到此一遊，看過的人懶覺都會被偷走
#ifdef DEBUG
#error 還敢看啊臭ㄐㄐ，臭到程式都跑不出來了
#endif
#pragma endregion
char dictionary[MAX__DICTIONARY][103], words[MAX__WORDS][100];
int dictionary__words__length[MAX__DICTIONARY] = {};
int N, Q;
int find(char[]);
void spellcheck(char[]);
#pragma region "main"
int main(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", dictionary[i]);
		dictionary__words__length[i] = strlen(dictionary[i]);
	}
	scanf("%d", &Q);
	for (i = 0; i < Q; i++)
	{
		scanf("%s", words[i]);
		if (find(words[i]))
		{
			printf(">%s\n", words[i]);
			continue;
		}
		spellcheck(words[i]);
	}
	return 0;
}
#pragma endregion
#pragma region "find function"
int find(char word[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (!strcmp(dictionary[i], word))
		{
			return 1;
		}
	}
	return 0;
}
#pragma endregion
#pragma region "spell check"
void spellcheck(char word[])
{
	int len = strlen(word);
	int i, j, k, difference;
	bool found = false, first__word = false;
	for (i = 0; i < N; i++)
	{
		if (dictionary__words__length[i] < len - 1 || dictionary__words__length[i] > len + 1)
		{
			continue;
		}
		else if (dictionary__words__length[i] == len)
		{
			difference = 0;
			for (j = 0; j < len && difference < 2; j++)
			{
				difference += dictionary[i][j] != word[j];
			}
			found = difference <= 1;
		}
		else if (dictionary__words__length[i] == len - 1)
		{
			difference = 0;
			for (j = 0, k = 0; j < len && difference < 2; j++)
			{
				if (dictionary[i][j] != word[k])
				{
					k++;
					difference++;
					j--;
				}
				else
				{
					k++;
				}
			}
			found = difference <= 1;
		}
		else if (dictionary__words__length[i] == len + 1)
		{
			difference = 0;
			for (j = 0, k = 0; k < len && difference < 2; j++)
			{
				if (dictionary[i][j] != word[k])
				{
					difference++;
				}
				else
				{
					k++;
				}
			}
			found = difference <= 1;
		}
		if (found)
		{
			if (!first__word)
			{
				printf("?");
				first__word = true;
			}
			else
			{
				printf(" ");
			}
			printf("%s", dictionary[i]);
		}
	}
	if (!first__word)
	{
		printf("!%s\n", word);
	}
	else
	{
		printf("\n");
	}
}
#pragma endregion