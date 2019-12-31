#include <stdio.h>
#include "ta_set.h"
#define MAX_K 100
void find(int now, int len, int *ans_len, ta_Set S, int n, ta_Set T[],
		  int max[], int k, ta_Set *tmp, ta_Set *ans)
{
	if (now > n + 1)
	{
		return;
	}
	if (now == n + 1)
	{
		int count = 0;
		for (int i = 0; i < k; i++)
		{
			if (intersect(T[i], (*tmp)))
			{
				count++;
			}
		}
		if (count == k)
		{
			if (len < *ans_len)
			{
				(*ans) = (*tmp);
				*ans_len = len;
			}
#ifdef SMALLESTDICTIONARYORDER
			return;
#elif defined LARGESTDICTIONARYORDER
			else if (len == *ans_len)
			{
				(*ans) = (*tmp);
			}
#endif
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (now > max[i] && !intersect(T[i], *tmp))
		{
			return;
		}
	}
	addElement(tmp, now);
	find(now + 1, len + 1, ans_len, S, n, T, max, k, tmp, ans);
	removeElement(tmp, now);
	find(now + 1, len, ans_len, S, n, T, max, k, tmp, ans);
}
int main(void)
{
	int i, j, n;
	scanf("%d", &n);
	ta_Set S;
	initializeSet(&S, n);
	for (i = 1; i <= n; i++)
	{
		addElement(&S, i);
	}
	int k;
	scanf("%d", &k);
	ta_Set T[MAX_K];
	int count, element, max[MAX_K];
	for (i = 0; i < k; i++)
	{
		scanf("%d", &count);
		initializeSet(&T[i], count);
		for (j = 0; j < count; j++)
		{
			scanf("%d", &element);
			addElement(&T[i], element);
			if (j == count - 1)
			{
				max[i] = element;
			}
		}
	}
	int ans_len = n;
	ta_Set ans = S, tmp;
	initializeSet(&tmp, n);
	find(1, 0, &ans_len, S, n, T, max, k, &tmp, &ans);
	printSet(ans);
	return 0;
}