#include <stdio.h>
#include <assert.h>
#define MAX_BUF 65536
int main(void)
{
	int i, key, size;
	char buffer[MAX_BUF];
	FILE *in = fopen("test", "rb");
	assert(in != NULL);
	FILE *out = fopen("test.enc", "wb");
	assert(out != NULL);
	scanf("%d", &key);
	while ((size = fread(buffer, 1, MAX_BUF, in)) != 0)
	{
		for (i = 0; i < size; i++)
		{
			buffer[i] ^= key;
		}
		fwrite(buffer, sizeof(char), size, out);
	}
	fclose(in);
	fclose(out);
	return 0;
}