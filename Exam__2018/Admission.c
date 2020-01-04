#include <stdio.h>
#include <stdlib.h>
#define MAX_N 20000
typedef struct Student
{
	int id;
	/* 0:國 1:英 2:數 3:自 4:社 */
	int score[5];
	int sum;
	int weightedSum;
} student;
int comp(const void *x, const void *y)
{
	student *a = (student *)y, *b = (student *)x;
	const int sequence[5] = {2, 1, 3, 0, 4};
	if (a->sum == b->sum)
	{
		for (int i = 0; i < 5; i++)
		{
			if (a->score[sequence[i]] != b->score[sequence[i]])
			{
				return a->score[sequence[i]] > b->score[sequence[i]];
			}
		}
		return a->id < b->id;
	}
	else
	{
		return a->sum > b->sum;
	}
}
int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	student students[MAX_N];
	int i, j;
	const int weight[5] = {2, 4, 5, 3, 1};
	for (i = 0; i < n; i++)
	{
		scanf("%d", &students[i].id);
		students[i].sum = 0;
		students[i].weightedSum = 0;
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &students[i].score[j]);
			students[i].sum += students[i].score[j];
			students[i].weightedSum += students[i].score[j] * weight[j];
		}
	}
	qsort(students, n, sizeof(students[0]), comp);
	for (i = 1; i <= m; i++)
	{
		printf("%d\n", students[i - 1].id);
		if (i < n && i == m && students[i].weightedSum == students[i - 1].weightedSum)
		{
			m++;
		}
	}
	return 0;
}