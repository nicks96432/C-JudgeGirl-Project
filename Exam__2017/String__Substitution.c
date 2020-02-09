#include <stdio.h>
#include <string.h>
#define MAX_LEN 1024
int main(void)
{
	char string[MAX_LEN * 2], command[MAX_LEN];
	scanf("%s", string);
	while (scanf("%s", command) != EOF)
	{
		const int len = strlen(command);
		if (command[0] == 'p')
		{
			puts(string);
		}
		else if (command[0] == 's')
		{
			char key[MAX_LEN] = {}, sub[MAX_LEN] = {};
			for (int i = 2; i < len; i++)
			{
				if (command[i] == command[1])
				{
					strncpy(key, command + 2, i - 2);
					strncpy(sub, command + i + 1, len - i - 2);
					break;
				}
			}
			char *found = strstr(string, key);
			if (!found)
			{
				continue;
			}
			char tmp[MAX_LEN * 2] = {};
			strncpy(tmp, string, found - string);
			strcat(tmp, sub);
			strcat(tmp, found + strlen(key));
			memset(string, 0, sizeof(string));
			strcpy(string, tmp);
		}
	}
	return 0;
}