#include <stdio.h>
#include <string.h>
#define abs(x) ((x) > (0)? (x): (-(x)))
void reverse__char()
int main(void)
{
	int i, j, k, n, count, count__2;
	char a[100], b[100], tmp[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int alphabet__a[26] = {0}, alphabet__b[26] = {0};
		scanf("%s", a);
		scanf("%s", b);
		int len__a = strlen(a), len__b = strlen(b);
		if (abs(len__a - len__b) > 1)
		{
			printf("no\n");
		}
		else
		{
			for (j = 0; j < len__a; j++)
			{
				alphabet__a[a[i] - 'a']++;
			}
			for (j = 0; j < len__b; j++)
			{
				alphabet__b[b[i] - 'a']++;
			}
			if (len__a == len__b)
			{
				count = 0;
				for (j = 0; j < 26; j++)
				{
					if (alphabet__a[j] == alphabet__b[j])
					{
						count++;
					}
				}
				if (count == 26)
				{
					printf("yes\n");
					continue;
				}
			}
			else
			{
				for (i = 0;; i++)
				{
					if (a[i] != a[j])
					{
						break;
					}
				}
			}
		}
	}
	return 0;
}