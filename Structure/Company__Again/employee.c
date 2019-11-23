#include "employee.h"
int relation(Employee *employee1, Employee *employee2)
{
	Employee *tmp1 = employee1, *tmp2 = employee2;
	while (tmp1 != tmp1->boss)
	{
		if (tmp1->boss == employee2)
		{
			return 1;
		}
		tmp1 = tmp1->boss;
	}
	if (tmp1->boss == employee2)
	{
		return 1;
	}
	while (tmp2 != tmp2->boss)
	{
		if (tmp2->boss == employee1)
		{
			return 2;
		}
		tmp2 = tmp2->boss;
	}
	if (tmp2->boss == employee1)
	{
		return 2;
	}
	if (tmp1 == tmp2)
	{
		return 3;
	}
	return 4;
}