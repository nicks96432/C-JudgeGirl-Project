#include <stdio.h>
#include <string.h>
#define MAX_BUFFER (1 << 13)
int main(void)
{
	int i;
	char in1[35], in2[35], out[35];
	scanf("%s %s %s", in1, in2, out);
	FILE *fin1, *fin2, *fout;
	fin1 = fopen(in1, "rb");
	fin2 = fopen(in2, "rb");
	fout = fopen(out, "wb");
	// fseek 讓你到你想要到的地方
	// ftell 告訴你現在在哪裡
	// rewind 讓你回到原點
	fseek(fin1, 0, SEEK_END);
	fseek(fin2, 0, SEEK_END);
	long size1 = ftell(fin1);
	long size2 = ftell(fin2);
	if (size1 < size2)
	{
		long tmp = size1;
		size1 = size2;
		size2 = tmp;
		FILE *tmpptr = fin1;
		fin1 = fin2;
		fin2 = tmpptr;
	}
	int carry = 0, sum;
	unsigned char c1, c2;
	unsigned char buffer1[MAX_BUFFER], buffer2[MAX_BUFFER];
	while (size1 > MAX_BUFFER && size2 > MAX_BUFFER)
	{
		memset(buffer1, 0, sizeof(buffer1));
		memset(buffer2, 0, sizeof(buffer2));
		fseek(fin1, size1 - MAX_BUFFER, SEEK_SET);
		fread(buffer1, sizeof(unsigned char), MAX_BUFFER, fin1);
		fseek(fin2, size2 - MAX_BUFFER, SEEK_SET);
		fread(buffer2, sizeof(unsigned char), MAX_BUFFER, fin2);
		for (i = MAX_BUFFER - 1; i >= 0; i--)
		{
			sum = carry + buffer1[i] + buffer2[i];
			if (sum > 255)
			{
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			fseek(fout, size1 - MAX_BUFFER + i, SEEK_SET);
			fwrite(&sum, sizeof(unsigned char), 1, fout);
		}
		size1 -= MAX_BUFFER;
		size2 -= MAX_BUFFER;
	}
	for (i = 0; i < size1; i++)
	{
		fseek(fin1, size1 - i - 1, SEEK_SET);
		c1 = fgetc(fin1);
		if (i < size2)
		{
			fseek(fin2, size2 - i - 1, SEEK_SET);
			c2 = fgetc(fin2);
		}
		else
		{
			c2 = 0;
		}
		sum = carry + c1 + c2;
		if (sum > 255)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		fseek(fout, size1 - i - 1, SEEK_SET);
		fwrite(&sum, sizeof(unsigned char), 1, fout);
	}
	fclose(fin1);
	fclose(fin2);
	fclose(fout);
	return 0;
}