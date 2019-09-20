#include <stdio.h>
#include <string.h>
#define abs(x) ((x) > (0) ? (x) : (-(x)))
int main(void)
{
	int i, j, k, n, count, count__change;
	char a[100], b[100];
	int alphabet__a[26] = {0}, alphabet__b[26] = {0};
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", a);
		scanf("%s", b);
		int len__a = strlen(a), len__b = strlen(b);
		memset(alphabet__a, 0, 26);
		memset(alphabet__b, 0, 26);
		if (abs(len__a - len__b) > 1)
		{
			printf("no\n");
		}
		else if (len__a == len__b)
		{
			for (j = 0; j < len__a; j++)
			{
				alphabet__a[a[j] - 'a']++;
			}
			for (j = 0; j < len__b; j++)
			{
				alphabet__b[b[j] - 'a']++;
			}
			count = 0;
			count__change = 0;
			for (j = 0; j < 26; j++)
			{
				if (alphabet__a[j] == alphabet__b[j])
				{
					count++;
				}
			}
			for (j = 0; j < len__a; j++)
			{
				if (a[j] != b[j])
				{
					count__change++;
				}
			}
			if (count == 26 && count__change <= 2)
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
		else
		{
			for (j = 0;; j++)
			{
				if (a[j] != b[j])
				{
					break;
				}
			}
			if (len__a > len__b)
			{
				for (k = j + 1; j < len__b, k < len__a; j++, k++)
				{
					if (a[k] != b[j])
					{
						break;
					}
				}
				if (k == len__a && j == len__b)
				{
					printf("yes\n");
				}
				else
				{
					printf("no\n");
				}
			}
			else
			{
				for (k = j + 1; j < len__a, k < len__b; j++, k++)
				{
					if (a[j] != b[k])
					{
						break;
					}
				}
				if (j == len__a && k == len__b)
				{
					printf("yes\n");
				}
				else
				{
					printf("no\n");
				}
			}
		}
	}
	return 0;
}