#include <stdio.h>
int main(void)
{
	char namein[16], nameout[16];
	int n;
	scanf("%s%s%d", namein, nameout, &n);
	FILE *fin, *fout;
	fin = fopen(namein, "rb");
	fout = fopen(nameout, "wb");
	fseek(fin, 0, SEEK_END);
	const int len = ftell(fin);
	unsigned char byte, mirror;
	int i, j;
	for (i = 0; i < len; i++)
	{
		fseek(fin, -((n + i) % len + 1), SEEK_END);
		fread(&byte, sizeof(unsigned char), 1, fin);
		mirror = 0;
		for (j = 0; j < 8; j++)
		{
			if (byte & (1 << j))
			{
				mirror |= 1 << (7 - j);
			}
		}
		fwrite(&mirror, sizeof(unsigned char), 1, fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}