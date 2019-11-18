#include <stdio.h>
#include <limits.h>
#define MAX_N 25
#define MAX_P 260
int diff(unsigned char a, unsigned char b)
{
	int count = 0;
	unsigned char i;
	for (i = ((unsigned char)1 << 7); i > 0; i >>= 1)
	{
		if ((a & i) != (b & i))
		{
			count++;
		}
	}
	return count;
}
int main(void)
{
	int n, m, p;
	unsigned char valid[MAX_N * 8], text[MAX_P];
	int i, j, count = 0;
	unsigned long long codes, tmp;
	scanf("%d%d%d", &n, &m, &p);
	for (i = 0; i < m; i++)
	{
		scanf("%llu", &codes);
		for (tmp = 0xFF00000000000000ULL, j = 7; tmp > 0; tmp >>= 8, j--)
		{
			valid[count] = (codes & tmp) >> (j * 8);
			count++;
		}
	}
	for (i = 0; i < p; i++)
	{
		scanf("%hhu", &text[i]);
	}
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (diff(text[i], valid[j]) <= 1)
			{
				printf("%hhu\n", valid[j]);
				break;
			}
		}
	}
	return 0;
}