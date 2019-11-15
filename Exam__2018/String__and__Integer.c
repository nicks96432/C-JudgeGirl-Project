#include <stdio.h>
#include <string.h>
#define MAX_STRING 150000
char string[MAX_STRING];
int main(void)
{
	int T, count__string = 0, i, count__int, n;
	unsigned long long integer, and, tmp;
	memset(string, 0, sizeof(string));
	scanf("%d", &T);
	if (T == 0)
	{
		integer = 0ULL;
		count__int = 8;
		scanf("%s", string);
		const int len = strlen(string);
		for (i = 0; i <= len; i++)
		{
			if (count__int == 0)
			{
				printf("%llu\n", integer);
				integer = 0ULL;
				count__int = 8;
			}
			if (string[i] == '\0')
			{
				printf("%llu\n", integer);
				break;
			}
			tmp = (unsigned long long)string[i];
			integer |= tmp << (count__int * 8 - 8);
			count__int--;
		}
	}
	else if (T == 1)
	{
		scanf("%d", &n);
		count__string = 0;
		while (scanf("%llu", &integer) != EOF)
		{
			and = 0x00000000000000FFULL;
			for (i = 0; i < 8; i++)
			{
				string[count__string] = (integer & (and << ((7 - (count__string % 8)) * 8))) >> ((7 - (count__string % 8)) * 8);
				count__string++;
			}
		}
		printf("%s", string);
	}
	return 0;
}
