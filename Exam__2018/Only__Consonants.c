#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char prev, tmp;
	int ans = 0;
	while (scanf("%c", &prev) != EOF)
	{
		if (prev != 'a' && prev != 'e' && prev != 'i' && prev != 'o' && prev != 'u' && prev != ' ' && prev != '\n' && prev != '\0')
		{
			break;
		}
	}
	while (scanf("%c", &tmp) != EOF)
	{
		if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u' || tmp == ' ' || tmp == '\n' || tmp == '\0')
		{
			continue;
		}
		else
		{
			if (prev < tmp)
			{
				ans++;
			}
			prev = tmp;
		}
	}
	printf("%d", ans);
	return 0;
}