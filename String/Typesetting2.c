#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, j, n, count__word = 0, count__len = 0, blank, extra__blank;
	char word[256], tmp[100][256], tmp2[256];
	memset(tmp, '\0', sizeof(tmp) / sizeof(char));
	scanf("%d", &n);
	while (1)
	{
		if (scanf("%s", word) != EOF)
		{
			count__len += strlen(word);
			strcpy(tmp[count__word], word);
			count__word++;
			if (n - count__len < count__word - 1)
			{
				count__word--;
				count__len -= strlen(word);
				if (count__word > 1)
				{
					blank = (n - count__len) / (count__word - 1);
					extra__blank = (n - count__len) % (count__word - 1);
					for (i = 0; i < extra__blank; i++)
					{
						printf("%s", tmp[i]);
						for (j = 0; j < blank + 1; j++)
						{
							printf(" ");
						}
					}
					for (; i < count__word - 1; i++)
					{
						printf("%s", tmp[i]);
						for (j = 0; j < blank; j++)
						{
							printf(" ");
						}
					}
					printf("%s\n", tmp[i]);
					strcpy(tmp2, tmp[count__word]);
					memset(tmp, '\0', sizeof(tmp) / sizeof(char));
					strcpy(tmp[0], tmp2);
					count__word = 1;
					count__len = strlen(tmp[0]);
					memset(tmp2, '\0', sizeof(tmp2) / sizeof(char));
				}
				else
				{
					blank = n - count__len;
					extra__blank = 0;
					printf("%s",tmp[0]);
					for(i=0;i<blank;i++)
					{
						printf(" ");
					}
					printf("\n");
					strcpy(tmp2, tmp[count__word]);
					memset(tmp, '\0', sizeof(tmp) / sizeof(char));
					strcpy(tmp[0], tmp2);
					count__word = 1;
					count__len = strlen(tmp[0]);
					memset(tmp2, '\0', sizeof(tmp2) / sizeof(char));
				}
			}
		}
		else
		{
			if (count__word > 1)
			{
				blank = (n - count__len) / (count__word - 1);
				extra__blank = (n - count__len) % (count__word - 1);
				for (i = 0; i < extra__blank; i++)
				{
					printf("%s", tmp[i]);
					for (j = 0; j < blank + 1; j++)
					{
						printf(" ");
					}
				}
				for (; i < count__word - 1; i++)
				{
					printf("%s", tmp[i]);
					for (j = 0; j < blank; j++)
					{
						printf(" ");
					}
				}
				printf("%s\n", tmp[i]);
			}
			else
			{
				blank = n - count__len;
				printf("%s", tmp[0]);
				for (i = 0; i < blank; i++)
				{
					printf(" ");
				}
				printf("\n");
			}
			break;
		}
	}
	return 0;
}