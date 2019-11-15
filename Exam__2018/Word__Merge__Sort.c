#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, j, tmplen, tmp2len;
	long long comp1, comp2;
	char ans[100003], tmp[100003], tmp2[100003];
	scanf("%s", ans);
	while (scanf("%s", tmp2) != EOF)
	{
		strcpy(tmp, ans);
		memset(ans, 0, sizeof(ans));
		tmplen = strlen(tmp);
		tmp2len = strlen(tmp2);
		for (i = 0, j = 0; i < tmplen && j < tmp2len;)
		{
			comp1 = tmp[i] * 1000000 + tmp[i + 1] * 1000 + tmp[i + 2];
			comp2 = tmp2[j] * 1000000 + tmp2[j + 1] * 1000 + tmp2[j + 2];
			if (comp1 < comp2)
			{
				strncat(ans, tmp + i, 3);
				i += 3;
			}
			else
			{
				strncat(ans, tmp2 + j, 3);
				j += 3;
			}
		}
		strcat(ans, tmp + i);
		strcat(ans, tmp2 + j);
		printf("%s\n", ans);
	}
	return 0;
}