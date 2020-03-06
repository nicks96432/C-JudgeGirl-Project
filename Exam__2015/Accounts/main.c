#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "account.h"
#define MAX_N 100000
#define AGE 1
#define ZIPCODE 2
int compAccountNum(const void *x, const void *y)
{
	Account *a = (Account *)x, *b = (Account *)y;
	if (a->accountNum > b->accountNum)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int compZipcodeOrAge(const void *x, const void *y)
{
	Account *a = (Account *)x, *b = (Account *)y;
#if (SORTBY == ZIPCODE)
	if (a->zipcode > b->zipcode)
	{
		return 1;
	}
	else if (a->zipcode < b->zipcode)
	{
		return -1;
	}
#elif (SORTBY == AGE)
	if (a->age > b->age)
	{
		return 1;
	}
	else if (a->age < b->age)
	{
		return -1;
	}
#endif
	return 0;
}
int main(void)
{
	char filename[32];
	scanf("%s", filename);
	FILE *input = fopen(filename, "rb");
	assert(input != NULL);
	Account accounts[MAX_N];
	int n = fread(accounts, sizeof(Account), MAX_N, input);
	fclose(input);
	qsort(accounts, n, sizeof(Account), compAccountNum);
	puts("account, age, zipcode, balance");
	for (int i = 0; i < n; i++)
	{
		printf("%d, %d, %d, %d\n", accounts[i].accountNum, accounts[i].age,
			   accounts[i].zipcode, accounts[i].balance);
	}
	qsort(accounts, n, sizeof(Account), compZipcodeOrAge);
	int sum = accounts[0].balance;
	int now = 0;
#if (SORTBY == ZIPCODE)
	puts("zipcode, sum_balance");
	for (int i = 1; i < n; i++)
	{
		if (accounts[i].zipcode == accounts[now].zipcode)
		{
			sum += accounts[i].balance;
		}
		else
		{
			printf("%d, %d\n", accounts[now].zipcode, sum);
			now = i;
			sum = accounts[i].balance;
		}
	}
	printf("%d, %d\n", accounts[now].zipcode, sum);
#elif (SORTBY == AGE)
	puts("age, sum_balance");
	for (int i = 1; i < n; i++)
	{
		if (accounts[i].age == accounts[now].age)
		{
			sum += accounts[i].balance;
		}
		else
		{
			printf("%d, %d\n", accounts[now].age, sum);
			now = i;
			sum = accounts[i].balance;
		}
	}
	printf("%d, %d\n", accounts[now].age, sum);
#endif
	return 0;
}