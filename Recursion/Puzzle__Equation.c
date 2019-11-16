#include <stdio.h>
#include <string.h>
#include <ctype.h>
char string[3][26];
int len[3];
int wordlist[26];	/* 26字母對應編號 */
int trynum[26] = {}; /* 26字母對應數字 */
int count;
int find(int);
int main(void)
{
	int i, j, k;
	char tmp;
	scanf("%s %s %s", string[0], string[1], string[2]);
	for (i = 0; i < 3; i++)
	{
		len[i] = strlen(string[i]);
		/* 讓位數由小排到大 */
		for (j = 0, k = len[i] - 1; j < k; j++, k--)
		{
			tmp = string[i][j];
			string[i][j] = string[i][k];
			string[i][k] = tmp;
		}
	}
	/* 建表 */
	memset(wordlist, -1, sizeof(wordlist));
	count = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < len[0] || j < len[1] || j < len[2]; j++)
		{
			if (j >= len[i])
			{
				continue;
			}
			if (isalpha(string[i][j]))
			{
				if (wordlist[string[i][j] - 'A'] == -1)
				{
					wordlist[string[i][j] - 'A'] = count;
					count++;
				}
			}
		}
	}
	int yes = find(0);
	return 0;
}
int find(int now)
{
	int i, j, value[3] = {};
	if (now == count)
	{
		/* 檢查 */
		for (i = 0; i < 3; i++)
		{
			for (j = len[i] - 1; j >= 0; j--)
			{
				if (isalpha(string[i][j]))
				{
					value[i] = value[i] * 10 + trynum[wordlist[string[i][j] - 'A']];
				}
				else
				{
					value[i] = value[i] * 10 + string[i][j] - '0';
				}
			}
		}
		if (value[0] * value[1] == value[2])
		{
			for (i = 0; i < 3; i++)
			{
				for (j = len[i] - 1; j >= 0; j--)
				{
					if (isalpha(string[i][j]))
					{
						printf("%d", trynum[wordlist[string[i][j] - 'A']]);
					}
					else
					{
						printf("%c", string[i][j]);
					}
				}
				if (i == 0)
				{
					printf(" x ");
				}
				else if (i == 1)
				{
					printf(" = ");
				}
				else if (i == 2)
				{
					printf("\n");
				}
			}
			return 1;
		}
		return 0;
	}
	/* 找答案 */
	for (i = 0; i < 10; i++)
	{
		trynum[now] = i;
		if (find(now + 1))
		{
			return 1;
		}
	}
	return 0;
}