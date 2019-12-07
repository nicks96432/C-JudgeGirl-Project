#include <stdio.h>
int main(void)
{
	char filename[16];
	scanf("%s", filename);
	FILE *fin;
	int instruction, integer, i;
	char character, string[4];
	fin = fopen(filename, "rb");
	while (1)
	{
		if (fread(&instruction, sizeof(int), 1, fin) != 1)
		{
			break;
		}
		switch (instruction)
		{
		case 0:
			fread(&integer, sizeof(int), 1, fin);
			printf("%d", integer);
			break;
		case 1:
			for (i = 0; i < 4; i++)
			{
				fread(&character, sizeof(char), 1, fin);
				putchar(character);
			}
			break;
		case 2:
			fseek(fin, sizeof(int), SEEK_CUR);
			while (fread(&character, sizeof(char), 1, fin)==1 && character!='\0')
			{
				putchar(character);
			}
			break;
		case 3:
			fread(&integer, sizeof(int), 1, fin);
			fseek(fin, integer - 8, SEEK_CUR);
			break;
		case 4:
			fread(&integer, sizeof(int), 1, fin);
			fseek(fin, integer, SEEK_SET);
			break;
		case 5:
			fread(&integer, sizeof(int), 1, fin);
			fseek(fin, integer, SEEK_END);
			break;
		default:
			printf("Seek end");
			fclose(fin);
			return 0;
		}
	}
	printf("Seek end");
	fclose(fin);
	return 0;
}