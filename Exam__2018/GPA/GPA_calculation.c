#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GPA_calculation.h"
static const char gradelist[10][3] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "F"};
int comp(const void *x, const void *y)
{
	struct Student *a = (struct Student *)x;
	struct Student *b = (struct Student *)y;
	if (a->GPA > b->GPA)
	{
		return -1;
	}
	else if (a->GPA < b->GPA)
	{
		return 1;
	}
	return 0;
}
double findGPA(char grade[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (!strcmp(grade, gradelist[i]))
		{
			if (i <= 2)
			{
				return 4.3 - (double)i * 0.3;
			}
			else if (i <= 5)
			{
				return 3.3 - (double)(i - 3) * 0.3;
			}
			else if (i <= 8)
			{
				return 2.3 - (double)(i - 6) * 0.3;
			}
			else if (i == 9)
			{
				return 0.0;
			}
		}
	}
}
void GPA_calculation(struct Student all_student[], int N)
{
	int i, j;
	int award = (N / 20) + ((N % 20) != 0 ? 1 : 0);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < all_student[i].N_class; j++)
		{
			all_student[i].N_credit += all_student[i].all_class[j].academic_credit;
			all_student[i].GPA += findGPA(all_student[i].all_class[j].score) * all_student[i].all_class[j].academic_credit;
		}
		all_student[i].GPA /= all_student[i].N_credit;
	}
	qsort((void *)all_student, N, sizeof(all_student[0]), comp);
	for (i = 0; i < award; i++)
	{
		if (all_student[i].GPA < 3.38)
		{
			break;
		}
		if (all_student[i].N_credit >= 15)
		{
			printf("%d %s %lf\n", i + 1, all_student[i].name, all_student[i].GPA);
		}
	}
	return;
}