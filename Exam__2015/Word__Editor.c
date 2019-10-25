#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, j;
	char S[100002], command[100], find[2], replace[2];
	scanf("%s", S);
	int len = strlen(S);
	while (scanf("%s", command) != EOF)
	{
		if (!strcmp(command, "replace"))
		{
			scanf("%s %s", find, replace);
			for (i = 0; i < len; i++)
			{
				if (S[i] == find[0])
				{
					S[i] = replace[0];
				}
			}
		}
		else if (!strcmp(command, "remove"))
		{
			scanf("%s", find);
			for (i = j = 0; i < len; i++)
			{
				if (S[i] != find[0])
				{
					S[j] = S[i];
					j++;
				}
			}
			len = j;
			S[j] = '\0';
		}
		else if (!strcmp(command, "addhead"))
		{
			scanf("%s", find);
			S[len + 1] = '\0';
			for (i = len; i > 0; i--)
			{
				S[i] = S[i - 1];
			}
			S[0] = find[0];
			len++;
		}
		else if (!strcmp(command, "addtail"))
		{
			scanf("%s", find);
			strncat(S, find, 1);
			len++;
		}
		else if (!strcmp(command, "end"))
		{
			break;
		}
		else
		{
			printf("invalid command %s\n", command);
			return 0;
		}
	}
	printf("%s\n", S);
	return 0;
}