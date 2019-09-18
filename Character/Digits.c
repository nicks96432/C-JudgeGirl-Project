#include <stdio.h>
#include <string.h>
int main(void)
{
	char num[80];
	int a, b, i, j, k;
	while (scanf("%s", num) != EOF)
	{
		scanf("%d %d", &a, &b);
#ifdef DEBUG
		for (i = 0; i < strlen(num); i++)
		{
			printf("%c", num[i]);
		}
		printf("\n");
#endif
#ifndef DEBUG
		int const len = strlen(num);
		for (i = 0; i < b; i++)
		{
			for (j = 0; j < len; j++)
			{
				switch (num[j])
				{
				case '0':
				case '2':
				case '3':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					printf(" ");
					for (k = 0; k < ((a % 2 == 0) ? (a / 2) : ((a / 2) + 1)); k++)
					{
						printf("%c", num[j]);
					}
					printf(" ");
					break;
				case '1':
				case '4':
					for (k = 0; k < a; k++)
					{
						printf(" ");
					}
					break;
				default:
					break;
				}
			}
			printf("\n");
		}

#endif
	}
	return 0;
}