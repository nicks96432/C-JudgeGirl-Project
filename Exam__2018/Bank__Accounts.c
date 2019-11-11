#include <stdio.h>
#include <string.h>
#define MAX_USER 40
#define MAX_COMMAND 40
#define bool _Bool
#define false 0
#define true 1
enum command__name
{
	EARNS,
	SPENDS,
	GIVES,
	BECOMES
};
int main(void)
{
	int i, n;
	bool found__from, found__command, found__to;
	scanf("%d", &n);
	char username[MAX_USER][MAX_COMMAND];
	int balance[MAX_USER], amount;
	char tmp[MAX_COMMAND];
	int command;
	int from, to;
	const char commands[4][35] = {"earns", "spends", "gives", "becomes"};
	for (i = 0; i < n; i++)
	{
		scanf("%s%d", username[i], &balance[i]);
	}
	while (scanf("%s", tmp) != EOF)
	{
		found__command = false;
		found__from = false;
		found__to = false;
		command = -1;
		from = -1;
		to = -1;
		for (i = 0; i < n; i++)
		{
			if (!strcmp(username[i], tmp))
			{
				from = i;
				found__from = true;
				break;
			}
		}
		if (!found__from)
		{
			continue;
		}
		scanf("%s", tmp);
		for (i = 0; i < 4; i++)
		{
			if (strstr(tmp, commands[i]) != NULL)
			{
				command = i;
				found__command = true;
				break;
			}
		}
		switch (command)
		{
		case EARNS:
			scanf("%d", &amount);
			if (found__from)
			{
				balance[from] += amount;
			}
			break;
		case SPENDS:
			scanf("%d", &amount);
			if (found__from && balance[from] >= amount)
			{
				balance[from] -= amount;
			}
			break;
		case GIVES:
			scanf("%s", tmp);
			for (i = 0; i < n; i++)
			{
				if (!strcmp(username[i], tmp))
				{
					to = i;
					found__to = true;
					break;
				}
			}
			scanf("%d", &amount);
			if (found__from && found__to && balance[from] >= amount)
			{
				balance[from] -= amount;
				balance[to] += amount;
			}
			break;
		case BECOMES:
			scanf("%d", &amount);
			if (found__from)
			{
				balance[from] = amount;
			}
			break;
		default:
			break;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%s %d\n", username[i], balance[i]);
	}
	return 0;
}