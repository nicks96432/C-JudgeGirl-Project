#include <stdio.h>
int main(void)
{
	char s[102];
	scanf("%s", s);
	int i, vowel = 0, consonant = 0, digit = 0;
	for (i = 0;; i++)
	{
		if (s[i] == '\0')
		{
			break;
		}
		else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			vowel++;
		}
		else if (s[i] >= '0'&&s[i]<='9')
		{
			digit++;
		}
		else if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
		{
			consonant++;
		}
	}
	printf("%d %d %d %d", digit, vowel + consonant, vowel, consonant);
	return 0;
}