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
			if (i == 0)
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
						for (k = 0; k < a - 3; k++)
						{
							printf("%c", num[j]);
						}
						printf("  ");
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
			}
			else if (i == b / 2)
			{
				for (j = 0; j < len; j++)
				{
					switch (num[j])
					{
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '8':
					case '9':
						printf(" ");
						for (k = 0; k < a - 3; k++)
						{
							printf("%c", num[j]);
						}
						printf("  ");
						break;
					case '0':
					case '1':
					case '7':
						for (k = 0; k < a; k++)
						{
							printf(" ");
						}
						break;
					default:
						break;
					}
				}
			}
			else if (i < b / 2)
			{
				for (j = 0; j < len; j++)
				{
					switch (num[j])
					{
					case '1':
					case '2':
					case '3':
						for (k = 0; k < a - 2; k++)
						{
							printf(" ");
						}
						printf("%c", num[j]);
						printf(" ");
						break;
					case '5':
					case '6':
						printf("%c", num[j]);
						for (k = 0; k < a - 1; k++)
						{
							printf(" ");
						}
						break;
					case '0':
					case '4':
					case '7':
					case '8':
					case '9':
						printf("%c", num[j]);
						for (k = 0; k < a - 3; k++)
						{
							printf(" ");
						}
						printf("%c", num[j]);
						printf(" ");
						break;
					default:
						break;
					}
				}
			}
			else if (i > b / 2 && i < b - 1)
			{
				for (j = 0; j < len; j++)
				{
					switch (num[j])
					{
					case '1':
					case '3':
					case '4':
					case '5':
					case '7':
					case '9':
						for (k = 0; k < a - 2; k++)
						{
							printf(" ");
						}
						printf("%c ", num[j]);
						break;
					case '2':
						printf("%c", num[j]);
						for (k = 0; k < a - 1; k++)
						{
							printf(" ");
						}
						break;
					case '0':
					case '6':
					case '8':
						printf("%c", num[j]);
						for (k = 0; k < a - 3; k++)
						{
							printf(" ");
						}
						printf("%c ", num[j]);
						break;
					default:
						break;
					}
				}
			}
			else
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
					case '8':
						printf(" ");
						for (k = 0; k < a - 3; k++)
						{
							printf("%c", num[j]);
						}
						printf("  ");
						break;
					case '1':
					case '4':
					case '7':
					case '9':
						for (k = 0; k < a; k++)
						{
							printf(" ");
						}
						break;
					default:
						break;
					}
				}
			}
			printf("\n");
		}
#endif
	}
	return 0;
}