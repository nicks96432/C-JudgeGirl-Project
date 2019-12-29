#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_EXPENSE 10000
typedef struct Expense
{
	long long date;
	char category[32];
	int amount;
} expense;
int comp(const void *x, const void *y)
{
	expense *a = (expense *)x, *b = (expense *)y;
	if (a->date == b->date)
	{
		int stringcmp = strcmp(a->category, b->category);
		if (!stringcmp)
		{
			return a->amount - b->amount;
		}
		else
		{
			return stringcmp;
		}
	}
	else
	{
		return a->date - b->date > 0 ? 1 : -1;
	}
}
int main(void)
{
	int countExpense = 0, amount, i;
	long long year, month, day, date;
	char category[32];
	expense expenses[MAX_EXPENSE];
	bool found;
	while (scanf("%lld%lld%lld%s%d", &year, &month, &day, category, &amount) == 5)
	{
		date = year * 10000 + month * 100 + day;
		found = false;
		for (i = 0; i < countExpense; i++)
		{
			if (date == expenses[i].date && !strcmp(category, expenses[i].category))
			{
				expenses[i].amount += amount;
				found = true;
				break;
			}
		}
		if (!found)
		{
			expenses[countExpense] = (expense){date, "", amount};
			strcpy(expenses[countExpense].category, category);
			countExpense++;
		}
	}
	qsort(expenses, countExpense, sizeof(expenses[0]), comp);
	for (int i = 0; i < countExpense; i++)
	{
		printf("%lld %lld %lld %s %d\n", expenses[i].date / 10000,
			   (expenses[i].date % 10000 - expenses[i].date % 100) / 100,
			   expenses[i].date % 100, expenses[i].category, expenses[i].amount);
	}
	return 0;
}