#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void *ptr1, const void *ptr2)
{
	return (strcmp((char *)ptr1, (char *)ptr2));
}
int main(void)
{
	int m, n, i, j, k, compfood__a, compfood__b, count__tmp;
	_Bool food__flag = 0;
	int count[100];
	char ingredient[100][10][65], tmp__ingredient[10][65];
	char compare[10000][2][65];
	char food[100][65];
	memset(ingredient, '\0', sizeof(ingredient) / sizeof(char));
	memset(compare, '\0', sizeof(compare) / sizeof(char));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", food[i]);
		scanf("%d", &count[i]);
		for (j = 0; j < count[i]; j++)
		{
			scanf("%s", ingredient[i][j]);
		}
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%s", compare[i][0]);
		scanf("%s", compare[i][1]);
	}
#ifdef DEBUG
	for (i = 0; i < n; i++)
	{
		printf("%s ", food[i]);
		for (j = 0; j < count[i]; j++)
		{
			printf("%s ", ingredient[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < m; i++)
	{
		printf("%s %s\n", compare[i][0], compare[i][1]);
	}
	printf("\n");
#endif
	for (i = 0; i < m; i++)
	{
		count__tmp = 0;
		memset(tmp__ingredient, '\0', sizeof(tmp__ingredient) / sizeof(char));
		for (j = 0; j < n; j++)
		{
			if (strcmp(food[j], compare[i][0]) == 0)
			{
				compfood__a = j;
				break;
			}
		}
		for (j = 0; j < n; j++)
		{
			if (strcmp(food[j], compare[i][1]) == 0)
			{
				compfood__b = j;
				break;
			}
		}
		food__flag = 0;
		for (j = 0; j < count[compfood__a]; j++)
		{
			for (k = 0; k < count[compfood__b]; k++)
			{
				if (strcmp(ingredient[compfood__a][j], ingredient[compfood__b][k]) == 0)
				{
					strcpy(tmp__ingredient[count__tmp], ingredient[compfood__a][j]);
					count__tmp++;
					food__flag = 1;
				}
			}
		}
		qsort(tmp__ingredient, count__tmp, sizeof(char) * 65, comp);
		for(j=0;j<count__tmp-1;j++)
		{
			printf("%s ",tmp__ingredient[j]);
		}
		printf("%s",tmp__ingredient[j]);
		if (food__flag)
		{
			printf("\n");
		}
		else
		{
			printf("nothing\n");
		}
	}
	return 0;
}