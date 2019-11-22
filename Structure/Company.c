#include <stdio.h>
#include <string.h>
#define MAX_PANGFENG 32
typedef struct employee
{
	int id;
	char first_name[32];
	char last_name[32];
	int boss_id;
} pangfeng;
pangfeng list[MAX_PANGFENG];
int findboss(int id1, int id2, int n)
{
	int i, no1;
	for (i = 0; i < n; i++)
	{
		if (id1 == list[i].id)
		{
			no1 = i;
			break;
		}
	}
	if (id1 == list[no1].boss_id)
	{
		return 0;
	}
	if (list[no1].boss_id == id2)
	{
		return 1;
	}
	return findboss(list[no1].boss_id, id2, n);
}
void findrelationship(char firstname1[], char lastname1[], char firstname2[], char lastname2[], int n)
{
	int i, id1, id2;
	for (i = 0; i < n; i++)
	{
		if (!strcmp(list[i].first_name, firstname1) && !strcmp(list[i].last_name, lastname1))
		{
			id1 = list[i].id;
			break;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!strcmp(list[i].first_name, firstname2) && !strcmp(list[i].last_name, lastname2))
		{
			id2 = list[i].id;
			break;
		}
	}
	if (findboss(id1, id2, n))
	{
		printf("subordinate\n");
		return;
	}
	else if (findboss(id2, id1, n))
	{
		printf("supervisor\n");
		return;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			if (list[i].id == id1 || list[i].id == id2)
			{
				continue;
			}
			if (findboss(id1, list[i].id, n) && findboss(id2, list[i].id, n))
			{
				printf("colleague\n");
				return;
			}
		}
	}
	printf("unrelated\n");
	return;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %s %s %d", &list[i].id, list[i].first_name, list[i].last_name, &list[i].boss_id);
	}
	int m;
	char firstname1[32], lastname1[32], firstname2[32], lastname2[32];
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%s %s %s %s", firstname1, lastname1, firstname2, lastname2);
		findrelationship(firstname1, lastname1, firstname2, lastname2, n);
	}
	return 0;
}