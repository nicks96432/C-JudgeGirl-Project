#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char a[1024][160], ans[160] = "";
	int i = 0, j = 0;
	while (scanf("%s", a[i]) != EOF)
	{
		if (strcmp(a[i], "of") != 0 && strcmp(a[i], "and") != 0 && strcmp(a[i], "the") != 0 && strcmp(a[i], "at") != 0 && strcmp(a[i], "of.") != 0 && strcmp(a[i], "and.") != 0 && strcmp(a[i], "the.") != 0 && strcmp(a[i], "at.") != 0)
		{
			ans[j] = toupper(a[i][0]);
			j++;
		}
		if (a[i][strlen(a[i]) - 1] == '.')
		{
			j = 0;
			printf("%s\n", ans);
			memset(ans, '\0', sizeof(ans));
		}
		i++;
	}
	return 0;
}