#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grading.h"
#define MAX_STUDENT 500
#define MAX_SUBMIT 20
int comp(const void *x, const void *y)
{
	return *((int *)x + 1) < *((int *)y + 1) ? -1 : 1;
}
void grading(char answer[10][maxL], Submission *sub, int num_of_submission)
{
	int student[MAX_STUDENT], score, i, j, submit[MAX_STUDENT][MAX_SUBMIT][2], countsubmit[MAX_STUDENT];
	memset(student, -1, sizeof(student));
	memset(submit, -1, sizeof(submit));
	memset(countsubmit, 0, sizeof(countsubmit));
	for (i = 0; i < num_of_submission; i++)
	{
		score = 0;
		for (j = 0; j < 10; j++)
		{
			if (!strcmp(answer[j], sub[i].outputs[j]))
			{
				score += 10;
			}
		}
		if (student[sub[i].studentID] < score)
		{
			student[sub[i].studentID] = score;
		}
		submit[sub[i].studentID][countsubmit[sub[i].studentID]][0] = score;
		submit[sub[i].studentID][countsubmit[sub[i].studentID]][1] = sub[i].subID;
		countsubmit[sub[i].studentID]++;
	}
	for (i = 0; i < MAX_STUDENT; i++)
	{
		if (student[i] == -1)
		{
			continue;
		}
		qsort((void *)submit[i], countsubmit[i], sizeof(int) * 2, comp);
		for (j = 0; j < MAX_SUBMIT; j++)
		{
			if (submit[i][j][0] == -1)
			{
				break;
			}
			printf("Student %d gets %d with Submission %d.\n", i, submit[i][j][0], submit[i][j][1]);
		}
		printf("Student %d gets %d in this exam.\n", i, student[i]);
	}
	return;
}