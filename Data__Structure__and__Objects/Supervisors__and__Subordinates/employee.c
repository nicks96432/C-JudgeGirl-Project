#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "employee.h"
void init_storage(Employee **storage, int n)
{
	// allocate memory space to store employee data
	// no need to understand this function now.
	(*storage) = (Employee *)malloc(sizeof(Employee) * n);
	assert((*storage) != NULL);
}
void free_storage(Employee **storage)
{
	free(*storage);
	*storage = 0;
}
Employee *find_employee_by_id(Employee *set, int n, int id)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if ((set + i)->id == id)
		{
			return set + i;
		}
	}
	return NULL;
}
Employee *find_employee_by_name(Employee *set, int n, const char *first_name, const char *last_name)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (!(strcmp(set[i].first_name, first_name)) && !(strcmp(set[i].last_name, last_name)))
		{
			return set + i;
		}
	}
	return NULL;
}
Employee *find_root_boss(Employee *set, int n, Employee *employee)
{
	return find_employee_by_id(set, n, employee->boss_id);
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B)
{
	Employee *bossA = A, *bossB = B;
	while (bossA->id != bossA->boss_id)
	{
		if (bossA->boss_id == B->id)
		{
			return 1;
		}
		bossA = find_root_boss(set, n, bossA);
	}
	if (bossA->boss_id == B->id)
	{
		return 1;
	}
	while (bossB->id != bossB->boss_id)
	{
		if (bossB->boss_id == A->id)
		{
			return 2;
		}
		bossB = find_root_boss(set, n, bossB);
	}
	if (bossB->boss_id == A->id)
	{
		return 2;
	}
	if (bossA == bossB)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}
