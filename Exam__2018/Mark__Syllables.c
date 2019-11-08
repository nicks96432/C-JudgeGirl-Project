#include <stdio.h>
#include <string.h>
#define MAX_ALPHABET 10002
void swap(int *, int *);
int isvowel(char);
void find__and__print(char[], int);
void find__diff__and__print(char[], int, int);
int main(void)
{
	int syllable__i, syllable__j;
	char word[MAX_ALPHABET];
	memset(word, '\0', sizeof(word));
	while (scanf("%s %d %d", word, &syllable__i, &syllable__j) != EOF)
	{
		find__and__print(word, syllable__i);
		find__and__print(word, syllable__j);
		find__diff__and__print(word, syllable__i, syllable__j);
	}
	return 0;
}
void swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
	return;
}
int isvowel(char a)
{
	if (a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' || a == 'I' || a == 'o' || a == 'O' || a == 'u' || a == 'U')
	{
		return 1;
	}
	return 0;
}
void find__and__print(char word[], int syllable)
{
	const int len = strlen(word);
	int count, i;
	for (i = 0, count = 0; i < len && count < syllable; i++)
	{
		if (isvowel(word[i]))
		{
			count++;
		}
		printf("+");
	}
	for (; i < len; i++)
	{
		printf("%c", word[i]);
		if (isvowel(word[i]))
		{
			i++;
			break;
		}
	}
	for (; i < len; i++)
	{
		printf("+");
	}
	printf("\n");
	return;
}
void find__diff__and__print(char word[], int syllable__i, int syllable__j)
{
	const int len = strlen(word);
	int i, count;
	if (syllable__i > syllable__j)
	{
		swap(&syllable__i, &syllable__j);
	}
	for (i = 0, count = 0; i < len && count < syllable__i; i++)
	{
		if (isvowel(word[i]))
		{
			count++;
		}
		printf("%c", word[i]);
	}
	for (; i < len; i++)
	{
		printf("+");
		if (isvowel(word[i]))
		{
			i++;
			count++;
			break;
		}
	}
	for (; i < len && count < syllable__j; i++)
	{
		if (isvowel(word[i]))
		{
			count++;
		}
		printf("%c", word[i]);
	}
	for (; i < len; i++)
	{
		printf("+");
		if (isvowel(word[i]))
		{
			i++;
			count++;
			break;
		}
	}
	for (; i < len; i++)
	{
		printf("%c", word[i]);
	}
	printf("\n");
	return;
}