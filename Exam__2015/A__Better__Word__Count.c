#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_CHAR 1024
int main(void)
{
	int i, len, words = 0, lines = 0, bytes;
	char line[MAX_CHAR];
	char filename[32];
	scanf("%s", filename);
	FILE *fin = fopen(filename, "r");
	while (fgets(line, MAX_CHAR, fin))
	{
		lines++; //fgets會一直讀直到\n，所以可以這樣寫
		len = strlen(line);
		for (i = 0; i < len; i++)
		{
			if (isalpha(line[i]))
			{
				while (isalpha(line[i]))
				{
					i++;
				}
				words++;
			}
		}
	}
	bytes = ftell(fin);
	printf("%d %d %d\n", lines, words, bytes);
	fclose(fin);
	return 0;
}