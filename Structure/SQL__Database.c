#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#define MAX_USER 52
typedef struct PersonData
{
	char firstname[MAX_LEN];
	char lastname[MAX_LEN];
	char ID[MAX_LEN];
	int salary;
	int age;
} data;
enum dataname
{
	LASTNAME,
	FIRSTNAME,
	ID,
	SALARY,
	AGE
};
enum operators
{
	EQUAL,
	NOTEQUAL,
	BIGGER,
	SMALLER
};
const char commandlist[][20] = {"lastname", "firstname", "ID", "salary", "age"};
const char operatorlist[][6] = {"==", "!=", ">", "<"};
int find__command(char string[])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (!strcmp(string, commandlist[i]))
		{
			return i;
		}
	}
	return -1;
}
int find__operator(char operator[])
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (!strcmp(operator, operatorlist[i]))
		{
			return i;
		}
	}
	return -1;
}
void print(data user, int order[])
{
	int i;
	for (i = 0; i < 9; i++)
	{
		if (order[i] == LASTNAME)
		{
			printf("%s%c", user.lastname, order[i + 1] == -1 ? '\n' : ' ');
		}
		else if (order[i] == FIRSTNAME)
		{
			printf("%s%c", user.firstname, order[i + 1] == -1 ? '\n' : ' ');
		}
		else if (order[i] == ID)
		{
			printf("%s%c", user.ID, order[i + 1] == -1 ? '\n' : ' ');
		}
		else if (order[i] == SALARY)
		{
			printf("%d%c", user.salary, order[i + 1] == -1 ? '\n' : ' ');
		}
		else if (order[i] == AGE)
		{
			printf("%d%c", user.age, order[i + 1] == -1 ? '\n' : ' ');
		}
		else if (order[i] == -1)
		{
			break;
		}
	}
	return;
}
int main(void)
{
	data users[MAX_USER];
	int i, j;
	int n;
	int commands, count, compare, _operator, mark[MAX_USER], _order[9];
	char select[10], compare1[MAX_LEN], operator[3], compare2[MAX_LEN], order[9][20];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s %s %s %d %d", users[i].lastname, users[i].firstname, users[i].ID, &users[i].salary, &users[i].age);
	}
	scanf("%d", &commands);
	while (scanf("%s", select) != EOF)
	{
		if (strcmp(select, "select"))
		{
			continue;
		}
		count = 0;
		memset(order, 0, sizeof(order));
		memset(_order, -1, sizeof(_order));
		while (scanf("%s", order[count]))
		{
			if (!strcmp(order[count], "where"))
			{
				break;
			}
			_order[count] = find__command(order[count]);
			count++;
		}
		scanf("%s %s %s", compare1, operator, compare2);
		compare = find__command(compare1);
		_operator = find__operator(operator);
		switch (compare)
		{
		case LASTNAME:
			if (_operator == EQUAL)
			{
				for (i = 0; i < n; i++)
				{
					if (!strcmp(users[i].lastname, compare2))
					{
						print(users[i], _order);
					}
				}
			}
			else if (_operator == NOTEQUAL)
			{
				for (i = 0; i < n; i++)
				{
					if (strcmp(users[i].lastname, compare2))
					{
						print(users[i], _order);
					}
				}
			}
			break;
		case FIRSTNAME:
			if (_operator == EQUAL)
			{
				for (i = 0; i < n; i++)
				{
					if (!strcmp(users[i].firstname, compare2))
					{
						print(users[i], _order);
					}
				}
			}
			else if (_operator == NOTEQUAL)
			{
				for (i = 0; i < n; i++)
				{
					if (strcmp(users[i].firstname, compare2))
					{
						print(users[i], _order);
					}
				}
			}
			break;
		case ID:
			if (_operator == EQUAL)
			{
				for (i = 0; i < n; i++)
				{
					if (!strcmp(users[i].ID, compare2))
					{
						print(users[i], _order);
					}
				}
			}
			else if (_operator == NOTEQUAL)
			{
				for (i = 0; i < n; i++)
				{
					if (strcmp(users[i].ID, compare2))
					{
						print(users[i], _order);
					}
				}
			}
			break;
		case SALARY:
			if (_operator == EQUAL)
			{
				for (i = 0; i < n; i++)
				{
					if (users[i].salary == atoi(compare2))
					{
						print(users[i], _order);
					}
				}
			}
			else if (_operator == NOTEQUAL)
			{
				for (i = 0; i < n; i++)
				{
					if (users[i].salary != atoi(compare2))
					{
						print(users[i], _order);
					}
				}
			}
			else if (_operator == BIGGER)
			{
				for (i = 0; i < n; i++)
				{
					if (users[i].salary > atoi(compare2))
					{
						print(users[i], _order);
					}
				}
			}
			else if (_operator == SMALLER)
			{
				for (i = 0; i < n; i++)
				{
					if (users[i].salary < atoi(compare2))
					{
						print(users[i], _order);
					}
				}
			}
			break;
		case AGE:
			if (_operator == EQUAL)
			{
				for (i = 0; i < n; i++)
				{
					if (users[i].age == atoi(compare2))
					{
						print(users[i], _order);
					}
				}
			}
			else if (_operator == NOTEQUAL)
			{
				for (i = 0; i < n; i++)
				{
					if (users[i].age != atoi(compare2))
					{
						print(users[i], _order);
					}
				}
			}
			else if (_operator == BIGGER)
			{
				for (i = 0; i < n; i++)
				{
					if (users[i].age > atoi(compare2))
					{
						print(users[i], _order);
					}
				}
			}
			else if (_operator == SMALLER)
			{
				for (i = 0; i < n; i++)
				{
					if (users[i].age < atoi(compare2))
					{
						print(users[i], _order);
					}
				}
			}
			break;
		default:
			break;
		}
	}
	return 0;
}