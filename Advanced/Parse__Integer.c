#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	int i, len, start, num = 0;
	char buffer[1024], tmp;
	while (scanf("%s", buffer) != EOF)
	{
		start = 0;
		len = strlen(buffer);
		for (i = 0; i < len; i++)
		{
			tmp = buffer[i];
			if (isdigit(tmp))
			{
				start = 1;
				num = num * 10 + (tmp - '0');
			}
			if (isalpha(tmp) && start)
			{
				start = 0;
				printf("%d\n", num);
				num = 0;
			}
		}
	}
	if(start)
	{
		printf("%d\n",num);
	}
	return 0;
}