#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 100000
typedef struct Student
{
	char name[64];
	int height;
	int weight;
} student;
double BMI(int height, int weight)
{
	return (double)weight / (((double)height / 100.0) * ((double)height / 100.0));
}
int comp(const void *x, const void *y)
{
	student *a, *b;
	a = (student *)x;
	b = (student *)y;
	double BMI_A = BMI(a->height, a->weight);
	double BMI_B = BMI(b->height, b->weight);
	if (BMI_A > BMI_B)
	{
		return 11;
	}
	else if (BMI_A < BMI_B)
	{
		return -1;
	}
	else
	{
		if (a->weight > b->weight)
		{
			return 1;
		}
		else if (a->weight < b->weight)
		{
			return -1;
		}
		else
		{

			if (a->height > b->height)
			{
				return 1;
			}
			else if (a->height < b->height)
			{
				return -1;
			}
			else
			{
				return strcmp(a->name, b->name) < 0 ? -1 : 1;
			}
		}
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	student students[MAX_N];
	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d", students[i].name, &students[i].height, &students[i].weight);
	}
	qsort(students, n, sizeof(student), comp);
	for (i = 0; i < n; i++)
	{
		printf("%s %d %d\n", students[i].name, students[i].height, students[i].weight);
	}
	return 0;
}