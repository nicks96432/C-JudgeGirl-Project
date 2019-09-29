#include <stdio.h>
#include <string.h>
int main(void)
{
	unsigned int point__array[16384];
	int width, height, i, tmp;
	char one, zero, str[4];
	scanf("%d%d\n", &width, &height);
	fgets(str, sizeof(str) / sizeof(char), stdin);
	one = str[0];
	zero = str[2];
	int points = (width * height) / 32 + ((width * height % 32 == 0) ? 0 : 1);
	for (i = 0; i < points; i++)
	{
		scanf("%d", &point__array[i]);
	}
	for (i = 0; i < width * height; i++)
	{
		tmp = 1 << (31 - i % 32);
		tmp = tmp & point__array[i / 32];
		printf("%c", (tmp == 0) ? zero : one);
		if (i % width == width - 1)
		{
			printf("\n");
		}
	}
	return 0;
}