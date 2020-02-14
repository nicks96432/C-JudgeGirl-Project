#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 10000
int main(void)
{
	int n;
	scanf("%d", &n);
	int now, prev = -1, count = -1;
	for (int i = 0; i < n; i++)
	{
		unsigned int integer;
		scanf("%u", &integer);
		for (int j = 0; j < 32; j++)
		{
			count++;
			now = (integer & (1 << (31 - j))) ? 1 : 0;
			if (now != prev && prev != -1)
			{
				printf("\n");
				int space = count % 40;
				for (int k = 0; k < space; k++)
				{
					printf(" ");
				}
			}
			printf("%d", now);
			prev = now;
		}
	}
	return 0;
}