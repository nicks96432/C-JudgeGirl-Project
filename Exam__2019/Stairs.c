#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_BUF 35
int main(void)
{
	int i, j;
	int countstars = 0, len__buffer = 0;
	bool right = false;
	char prev__last = -1, buffer[MAX_BUF];
	if (scanf("%s", buffer) == EOF)
	{
		return 0;
	}
	else
	{
		printf("%s", buffer);
		countstars += strlen(buffer) - 1;
	}
	prev__last = buffer[strlen(buffer) - 1];
	while (scanf("%s", buffer) != EOF)
	{
		len__buffer = strlen(buffer);
		if (right)
		{
			if (prev__last == buffer[0])
			{
				for (i = 1; i < len__buffer; i++)
				{
					printf("%c", buffer[i]);
				}
			}
			else
			{
				printf("\n");
				for (i = 0; i < countstars; i++)
				{
					printf("*");
				}
				for (i = 0; i < len__buffer; i++)
				{
					printf("%c", buffer[i]);
				}
			}
			right = false;
			countstars += len__buffer - 1;
		}
		else
		{
			printf("\n");
			if (prev__last == buffer[0])
			{
				for (i = 1; i < len__buffer; i++)
				{
					for (j = 0; j < countstars; j++)
					{
						printf("*");
					}
					printf("%c", buffer[i]);
					if (i < len__buffer - 1)
					{
						printf("\n");
					}
				}
			}
			else
			{
				for (i = 0; i < len__buffer; i++)
				{
					for (j = 0; j < countstars; j++)
					{
						printf("*");
					}
					printf("%c", buffer[i]);
					if (i < len__buffer - 1)
					{
						printf("\n");
					}
				}
			}
			right = true;
		}
		prev__last = buffer[len__buffer - 1];
	}
	return 0;
}