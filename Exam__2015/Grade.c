#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_N 50
typedef struct Problem
{
	int choice[5];
} problem;
void initProblem(problem problems[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 5; j++)
		{
			problems[i].choice[j] = 0;
		}
	}
	return;
}
void transferProblem(problem *a, char tmp[])
{
	int i;
	if (strcmp(tmp, "N/A") == 0)
	{
		for (i = 0; i < 5; i++)
		{
			a->choice[i] = -1;
		}
		return;
	}
	for (i = 0; i < 10; i++)
	{
		switch (tmp[i])
		{
		case 'A':
		case 'a':
			a->choice[0] = 1;
			break;
		case 'B':
		case 'b':
			a->choice[1] = 1;
			break;
		case 'C':
		case 'c':
			a->choice[2] = 1;
			break;
		case 'D':
		case 'd':
			a->choice[3] = 1;
			break;
		case 'E':
		case 'e':
			a->choice[4] = 1;
			break;
		case '\0':
			return;
			break;
		default:
			break;
		}
	}
}
void readProblem(problem problems[], int n)
{
	int i;
	char tmp[10];
	for (i = 0; i < n; i++)
	{
		scanf("%s", tmp);
		transferProblem(&problems[i], tmp);
	}
	return;
}
int checkProblem(problem problems[], problem student[], int n, int r, int w)
{
	int score = 0, count;
	int i, j;
	for (i = 0; i < n; i++)
	{
		count = 0;
		for (j = 0; j < 5; j++)
		{
			if (problems[i].choice[j] == student[i].choice[j])
			{
				count++;
			}
		}
		if (student[i].choice[0] == -1)
		{
			continue;
		}
		if (count == 5)
		{
			score += r;
		}
		else
		{
			score -= w;
		}
	}
	if (score < 0)
	{
		score = 0;
	}
	return score;
}
int main(void)
{
	int n, r, w;
	int i;
	while (scanf("%d%d%d", &n, &r, &w) == 3)
	{
		problem problems[MAX_N];
		initProblem(problems, n);
		readProblem(problems, n);
		int countStudent;
		problem student[MAX_N];
		scanf("%d", &countStudent);
		for (i = 0; i < countStudent; i++)
		{
			initProblem(student, n);
			readProblem(student, n);
			printf("%d\n", checkProblem(problems, student, n, r, w));
		}
	}
}