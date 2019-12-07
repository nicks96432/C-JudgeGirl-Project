#include <stdio.h>
#include <assert.h>
#include "conversion.h"
void bin2ascii(char input_file[32], char output_file[32], char dict[17])
{
	FILE *fin, *fout;
	fin = fopen(input_file, "rb");
	fout = fopen(output_file, "w");
	assert(fin && fout);
	unsigned char twobyte;
	const unsigned char firstbyte = 0xF0, secondbyte = 0xF;
	while (fread(&twobyte, sizeof(unsigned char), 1, fin) == 1)
	{
		fwrite(&dict[(twobyte & firstbyte) >> 4], sizeof(char), 1, fout);
		fwrite(&dict[twobyte & secondbyte], sizeof(char), 1, fout);
		printf("%d %d\n", (twobyte & firstbyte) >> 4, twobyte & secondbyte);
	}
	fclose(fin);
	fclose(fout);
	return;
}
void ascii2bin(char input_file[32], char output_file[32], char dict[17])
{
	FILE *fin, *fout;
	fin = fopen(input_file, "rt");
	fout = fopen(output_file, "wb");
	assert(fin && fout);
	char i, flag = 0;
	unsigned char ch, tmp = 0;
	while (fread(&ch,sizeof(unsigned char),1,fin)==1)
	{
		for (i = 0; i < 17; i++)
		{
			if (ch == dict[i])
			{
				break;
			}
		}
		if (!flag)
		{
			flag = 1;
			tmp = (i << 4);
		}
		else
		{
			flag = 0;
			tmp |= i;
			fwrite(&tmp, sizeof(unsigned char), 1, fout);
		}
	}
	fclose(fin);
	fclose(fout);
	return;
}