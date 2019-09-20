#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(void)
{
	char a[256], ans[1048576];
	int len__a, len__ans, i, j, count, count__fusion = 0, fusion;
	fgets(ans, sizeof(ans) / sizeof(char), stdin);
	ans[strlen(ans) - 1] = '\0';
	while (fgets(a, sizeof(a) / sizeof(char), stdin) != NULL)
	{
		fusion = 0;
		a[strlen(a) - 1] = '\0';
		len__a = strlen(a);
		len__ans = strlen(ans);
		for (count__fusion = 1; count__fusion <= len__a; count__fusion++)
		{
			count = 0;
			for (i = len__ans - count__fusion, j = 0; i < len__ans && j < len__a; i++, j++)
			{
				if (ans[i] == a[j])
				{
					count++;
				}
			}
			if (count == count__fusion)
			{
				if (count__fusion > fusion)
				{
					fusion = count__fusion;
				}
			}
		}
		ans[len__ans-fusion]='\0';
		strcat(ans, a);
	}
	printf("%s\n", ans);
	return 0;
}
