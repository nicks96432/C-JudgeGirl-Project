#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(void)
{
	char command[10], position[10], character, ans[20000], tmp[20000];
	int i = 0, j, pos, len, max = 0, count = 0, list = 1;
	memset(ans, '\0', sizeof(ans) / sizeof(char));
	memset(tmp, '\0', sizeof(tmp) / sizeof(char));
	while (scanf("%s", command) != EOF)
	{
		if (strcmp(command, "insert") == 0)
		{
			memset(tmp, '\0', sizeof(tmp) / sizeof(char));
			scanf("%s ", position);
			scanf("%c", &character);
			if (strcmp(position, "left") == 0)
			{
				strcpy(tmp, ans);
				memset(ans, '\0', sizeof(ans) / sizeof(char));
				ans[0] = character;
				strcat(ans, tmp);
				ans[strlen(ans)] = '\0';
#ifdef DEBUG
				printf("%s\n", ans);
#endif
			}
			else if (strcmp(position, "right") == 0)
			{
				ans[strlen(ans)] = character;
#ifdef DEBUG
				printf("%s\n", ans);
#endif
			}
			else
			{
				len = strlen(ans);
				pos = atoi(position) - 1;
				for (i = len; i > pos; i--)
				{
					ans[i] = ans[i - 1];
				}
				ans[pos] = character;
#ifdef DEBUG
				printf("%s\n", ans);
#endif
			}
		}
		else //delete
		{
			scanf("%s", position);
			if (strcmp(position, "left") == 0)
			{
				for (i = 0; i < strlen(ans) - 1; i++)
				{
					ans[i] = ans[i + 1];
				}
				ans[i] = '\0';
#ifdef DEBUG
				printf("%s\n", ans);
#endif
			}
			else if (strcmp(position, "right") == 0)
			{
				ans[strlen(ans) - 1] = '\0';
#ifdef DEBUG
				printf("%s\n", ans);
#endif
			}
			else
			{
				len = strlen(ans);
				pos = atoi(position) - 1;
				for (i = pos; i < len; i++)
				{
					ans[i] = ans[i + 1];
				}
				ans[i] = '\0';
#ifdef DEBUG
				printf("%s\n", ans);
#endif
			}
		}
	}
	if (strlen(ans) == 0)
	{
		printf("0");
		return 0;
	}
	for (i = 0; i < strlen(ans); i++)
	{
		count = 1;
		for (j = i + 1; j < strlen(ans); j++)
		{
			if (ans[j] == '\0')
			{
				break;
			}
			if (ans[j] == ans[i])
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count > max)
		{
			max = count;
		}
	}
	for (i = 0; i < strlen(ans); i++)
	{
		count = 1;
		for (j = i + 1; j < strlen(ans); j++)
		{
			if (ans[j] == '\0')
			{
				break;
			}
			if (ans[j] == ans[i])
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count == max)
		{
			printf("%c ", ans[i]);
		}
	}
	printf("%d", max);
	return 0;
}
