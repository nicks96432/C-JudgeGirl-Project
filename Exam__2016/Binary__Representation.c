#include <stdio.h>
int main(void)
{
	char string[35];
	scanf("%s", string);
	int n;
	scanf("%d", &n);
	unsigned int num;
	int count = 0, value = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%u", &num);
		for (int j = 31; j >= 0; j--)
		{
			value = ((value << 1) | ((num >> j) & 1));
			count++;
			if (count % 5 == 0)
			{
				printf("%c", string[value]);
				value = 0;
			}
		}
	}
	printf("\n");
	return 0;
}