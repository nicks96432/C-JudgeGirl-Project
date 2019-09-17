#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[1000000]="", tmp[1000000];
	int sentence = 0;
	int i = 0, count__space = 0;
	while (fgets(tmp, 2147483647, stdin))
	{
		strcat(a, tmp);
	}
	int const len = strlen(a);
	for (i = 0; i < len; i++)
	{
		if (a[i] == '.' && ((a[i + 1] == ' ' && a[i + 2] == ' ') || (a[i + 1] == '\n' || a[i + 1] == '\0')))
		{
			sentence++;
		}
	}
	printf("%d", sentence);
	return 0;
}
