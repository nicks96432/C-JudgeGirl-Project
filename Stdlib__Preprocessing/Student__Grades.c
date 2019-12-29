#include <stdio.h>
int main(void)
{
	int score, count = 0;
	double sumGPA = 0.0;
	unsigned long long sum = 0;
	while (scanf("%d", &score) != EOF)
	{

#ifdef HUNDRED
		sum += score;
		printf("%d ", score);
#elif defined APLUS
		if (score >= 90) //APLUS
		{
			sumGPA += 4.3;
			sum += 95;
			printf("A+ ");
		}
		else if (score >= 85) //A
		{
			sumGPA += 4.0;
			sum += 87;
			printf("A ");
		}
		else if (score >= 80) //AMINUS
		{
			sumGPA += 3.7;
			sum += 82;
			printf("A- ");
		}
		else if (score >= 77) //BPLUS
		{
			sumGPA += 3.3;
			sum += 78;
			printf("B+ ");
		}
		else if (score >= 73) //B
		{
			sumGPA += 3.0;
			sum += 75;
			printf("B ");
		}
		else if (score >= 70) //BMINUS
		{
			sumGPA += 2.7;
			sum += 70;
			printf("B- ");
		}
		else if (score >= 67) //CPLUS
		{
			sumGPA += 2.3;
			sum += 68;
			printf("C+ ");
		}
		else if (score >= 63) //C
		{
			sumGPA += 2.0;
			sum += 65;
			printf("C ");
		}
		else if (score >= 60) //CMINUS
		{
			sumGPA += 1.7;
			sum += 60;
			printf("C- ");
		}
		else //F
		{
			sum += 50;
			printf("F ");
		}

#endif
		count++;
	}
#ifdef HUNDRED
	printf("%.1lf\n", (double)sum / count);
#elif defined APLUS
	printf("%.1lf %.1lf\n",sumGPA/count, (double)sum / count);
#endif
	return 0;
}