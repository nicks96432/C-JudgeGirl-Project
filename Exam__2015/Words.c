#include <stdio.h>
#include <string.h>
char word[32], rule[4], ans[32];
int rules[26][26], letters[26] = {};
int len, m;
void generate(int now)
{
	int i;
	if (now == len)
	{
		ans[now] = '\0';
		puts(ans);
		return;
	}
	if (now == 0)
	{
		for (i = 0; i < 26; i++)
		{
			if (letters[i] > 0)
			{
				letters[i]--;
				ans[now] = 'a' + i;
				generate(1);
				letters[i]++;
			}
		}
	}
	else
	{
		for (i = 0; i < 26; i++)
		{
			if (letters[i] > 0 && rules[ans[now - 1] - 'a'][i] == 0)
			{
				letters[i]--;
				ans[now] = 'a' + i;
				generate(now + 1);
				letters[i]++;
			}
		}
	}
}
int main(void)
{
	scanf("%s", word);
	memset(rules, 0, sizeof(rules));
	len = strlen(word);
	int i;
	for (i = 0; i < len; i++)
	{
		letters[word[i] - 'a']++;
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%s", rule);
		rules[rule[0] - 'a'][rule[1] - 'a'] = 1;
	}
	generate(0);
	return 0;
}