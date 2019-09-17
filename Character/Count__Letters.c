#include <stdio.h>
int main(void)
{
	char s[102];
	scanf("%s", s);
	int len;
	int i, letter[128] = {0};
	for (i = 0;; i++)
	{
		if (s[i] == '\0')
		{
			len = i;
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		letter[s[i]]++;
	}
	for (i = 65; i <= 90; i++)
	{
		letter[i] += letter[i + 32];
	}
	for (i = 65; i <= 90; i++)
	{
		printf("%d\n", letter[i]);
	}
	return 0;
}