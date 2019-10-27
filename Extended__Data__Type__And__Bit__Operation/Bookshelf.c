#include <stdio.h>
int hasEOF = 0;
void print__books(unsigned long long l)
{
	int i;
	for (i = 7; i > 0; i--)
	{
		printf("%lld ", (l & (255ULL << (i * 8))) >> (i * 8));
	}
	printf("%lld\n", (l & (255ULL << (i * 8))) >> (i * 8));
	return;
}
int find__book(unsigned long long bookshelf, int book)
{
	int i = 0;
	while (bookshelf % 256ULL != book && i < 8)
	{
		i++;
		bookshelf /= 256ULL;
	}
	return i;
}
/* 拿出第book本書 */
unsigned long long take__book(unsigned long long bookshelf, int book)
{
	unsigned long long count[9] = {0ULL};
	int i;
	count[0] = 255ULL;
	for (i = 1; i < 8; i++)
	{
		count[i] = count[0] << (i * 8);
	}
	unsigned long long dont__take = 0ULL;
	for (i = 0; i < 8; i++)
	{
		if (i != book)
		{
			dont__take |= count[i];
		}
	}
	bookshelf &= dont__take;
	return bookshelf;
}
unsigned long long put__book(unsigned long long bookshelf, int book)
{
	unsigned long long count[9] = {0ULL};
	int i;
	count[0] = 255ULL;
	for (i = 1; i < 8; i++)
	{
		count[i] = count[0] << (i * 8);
	}
	/* 在要拿的書左邊的所有書(要動的) */
	unsigned long long left = 0;
	/* 在要拿的書右邊的所有書(不可以動的) */
	unsigned long long right = 0;
	for (i = book + 1; i < 8; i++)
	{
		left |= count[i];
	}
	left &= bookshelf;
	for (i = 0; i < book; i++)
	{
		right |= count[i];
	}
	right &= bookshelf;
	right <<= 8;
	bookshelf = 0ULL;
	bookshelf |= left;
	bookshelf |= right;
	return bookshelf;
}
int readchar(void)
{
	static int N = 1 << 20;
	static char buf[1 << 20];
	static char *p = buf, *end = buf;
	if (p == end)
	{
		if ((end = buf + fread(buf, 1, N, stdin)) == buf)
		{
			hasEOF = 1;
			return EOF;
		}
		p = buf;
	}
	return *p++;
}
int ReadInt(int *x)
{
	char c, neg;
	while ((c = readchar()) < '-')
	{
		if (c == EOF)
			return 0;
	}
	neg = (c == '-') ? -1 : 1;
	*x = (neg == 1) ? c - '0' : 0;
	while ((c = readchar()) >= '0')
	{
		*x = (*x << 3) + (*x << 1) + c - '0';
	}
	*x *= neg;
	return 1;
}
int main(void)
{
	int x;
	int i, tmp;
	unsigned long long bookshelf = 0, count[9] = {0};
	count[0] = 255;
	for (i = 1; i < 8; i++)
	{
		count[i] = count[0] << (i * 8);
	}
	while (ReadInt(&x))
	{
		i = find__book(bookshelf, x);
		if (i != 8)
		{
			take__book(bookshelf, i);
		}
		if (i == 8)
		{
			bookshelf <<= 8;
		}
		else
		{
			bookshelf = put__book(bookshelf, i);
		}
		bookshelf |= (unsigned long long)x;
	}
	// output your answer
	print__books(bookshelf);
	return 0;
}