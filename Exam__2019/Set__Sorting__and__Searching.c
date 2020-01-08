#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10000
typedef struct set
{
	int *num;
	int countNum;
} set;
typedef struct Sets
{
	set s[MAX_N];
	int countSets;
} sets;
sets *genSets(int n)
{
	sets *newSet = (sets *)malloc(sizeof(sets));
	newSet->countSets = 0;
	return newSet;
}
int compNum(const void *x, const void *y)
{
	if ((*(int *)x) > (*(int *)y))
	{
		return -1;
	}
	else if ((*(int *)x) < (*(int *)y))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void readSets(sets *mysets, int n)
{
	mysets->countSets = n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &mysets->s[i].countNum);
		mysets->s[i].num = (int *)malloc(sizeof(int) * mysets->s[i].countNum);
		for (int j = 0; j < mysets->s[i].countNum; j++)
		{
			scanf("%d", &mysets->s[i].num[j]);
		}
		qsort(mysets->s[i].num, mysets->s[i].countNum, sizeof(int), compNum);
	}
	return;
}
int compSet(const void *x, const void *y)
{
	for (int i = 0; i < ((((set *)x)->countNum < ((set *)y)->countNum)
							 ? ((set *)x)->countNum
							 : ((set *)y)->countNum);
		 i++)
	{
		if (((set *)x)->num[i] > ((set *)y)->num[i])
		{
			return 1;
		}
		else if (((set *)x)->num[i] < ((set *)y)->num[i])
		{
			return -1;
		}
	}
	if (((set *)x)->countNum > ((set *)y)->countNum)
	{
		return 1;
	}
	else if (((set *)x)->countNum < ((set *)y)->countNum)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void sortSets(sets *mysets)
{
	qsort(mysets->s, mysets->countSets, sizeof(set), compSet);
	return;
}
void printSets(sets *mysets)
{
	for (int i = 0; i < mysets->countSets; i++)
	{
		for (int j = 0; j < mysets->s[i].countNum; j++)
		{
			printf("%d ", mysets->s[i].num[j]);
		}
		printf("\n");
	}
	return;
}
void freeSets(sets *mysets)
{
	for (int i = 0; i < mysets->countSets; i++)
	{
		free(mysets->s[i].num);
	}
	free(mysets);
	return;
}
void querySets(sets *mysets, int q)
{
	set query;
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &query.countNum);
		query.num = (int *)malloc(sizeof(int) * query.countNum);
		for (int j = 0; j < query.countNum; j++)
		{
			scanf("%d", &query.num[j]);
		}
		qsort(query.num, query.countNum, sizeof(int), compNum);
		set *find = bsearch(&query, mysets->s, mysets->countSets, sizeof(set), compSet);
		if (find == NULL)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", find - mysets->s);
		}
		free(query.num);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	sets *mysets = genSets(n);
	readSets(mysets, n);
	sortSets(mysets);
	int q;
	scanf("%d", &q);
	querySets(mysets, q);
	freeSets(mysets);
	return 0;
}