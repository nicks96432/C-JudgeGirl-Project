#include <stdio.h>
#include "computeGrade.h"
void adjust(Classes classes[2], double ratio, int quiznum, int class)
{
	int i;
	for (i = 0; i < classes[class].numStudent; i++)
	{
		classes[class].student[i].score[quiznum].scaledScore = (double)(classes[class].student[i].score[quiznum].rawScore) * ratio;
		if (classes[class].student[i].score[quiznum].scaledScore > 100.0)
		{
			classes[class].student[i].score[quiznum].scaledScore = 100.0;
		}
	}
	return;
}
void computeGrade(Classes classes[2])
{
	int i, j, k;
	double average[2], ratio;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < classes[i].numStudent; j++)
		{
			classes[i].student[j].finalScore = 0;
		}
	}
	for (i = 0; i < 18; i++)
	{
		for (j = 0; j < 2; j++)
		{
			average[j] = 0.0;
			for (k = 0; k < classes[j].numStudent; k++)
			{
				average[j] += classes[j].student[k].score[i].rawScore;
			}
			average[j] /= classes[j].numStudent;
		}
		ratio = 1.0;
		if (average[0] > average[1])
		{
			ratio = average[0] / average[1];
			adjust(classes, ratio, i, 1);
			adjust(classes, 1.0, i, 0);
		}
		else
		{
			ratio = average[1] / average[0];
			adjust(classes, ratio, i, 0);
			adjust(classes, 1, i, 1);
		}
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < classes[j].numStudent; k++)
			{
				classes[j].student[k].finalScore += classes[j].student[k].score[i].scaledScore;
			}
		}
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < classes[i].numStudent; j++)
		{
			classes[i].student[j].finalScore *= 0.06;
			if (classes[i].student[j].finalScore > 100)
			{
				classes[i].student[j].finalScore = 100;
			}
			printf("%s %lf\n", classes[i].student[j].id, classes[i].student[j].finalScore);
		}
	}
	return;
}