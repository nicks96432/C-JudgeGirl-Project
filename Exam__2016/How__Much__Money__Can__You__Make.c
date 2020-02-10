#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 100
typedef struct Material
{
	char name[60];
	int price;
	int amount;
} material;
typedef struct Product
{
	char name[60];
	int price;
	int cost;
	int maxAmount;
} product;
int findMaterial(char name[], material materials[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!strcmp(materials[i].name, name))
		{
			return i;
		}
	}
	exit(EXIT_FAILURE);
}
int comp(const void *x, const void *y)
{
	product *a = (product *)x;
	product *b = (product *)y;
	int profit_a = (a->price - a->cost) * a->maxAmount;
	int profit_b = (b->price - b->cost) * b->maxAmount;
	if (profit_a > profit_b)
	{
		return -1;
	}
	else if (profit_a < profit_b)
	{
		return 1;
	}
	else
	{
		return strcmp(a->name, b->name);
	}
}
int main(void)
{
	int n, m;
	material materials[MAX_N];
	product products[MAX_N];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d%d", materials[i].name, &materials[i].amount, &materials[i].price);
	}
	for (int i = 0; i < m; i++)
	{
		int countMaterial, amount, find;
		char tmp[60];
		scanf("%s%d", products[i].name, &countMaterial);
		products[i].cost = 0;
		products[i].maxAmount = 2147483647;
		for (int j = 0; j < countMaterial; j++)
		{
			scanf("%s%d", tmp, &amount);
			find = findMaterial(tmp, materials, n);
			products[i].cost += materials[find].price * amount;
			if (materials[find].amount / amount < products[i].maxAmount)
			{
				products[i].maxAmount = materials[find].amount / amount;
			}
		}
		scanf("%d", &products[i].price);
	}
	qsort(products, m, sizeof(product), comp);
	printf("%s %d\n", products[0].name,
		   products[0].maxAmount * (products[0].price - products[0].cost));
	return 0;
}