#include <stdio.h>
#include <string.h>
#define MAX_PERSON 10000
typedef struct Person
{
	unsigned int id;
	char name[32];
} person;
typedef struct Friend
{
	unsigned int id1;
	unsigned int id2;
} friend;
int main(void)
{
	FILE *fin = fopen("friends", "rb");
	int p;
	fread(&p, sizeof(int), 1, fin);
	int i;
	person persons[MAX_PERSON];
	for (i = 0; i < p; i++)
	{
		fread(&persons[i], sizeof(person), 1, fin);
	}
	int f;
	fread(&f, sizeof(int), 1, fin);
	friend friends[MAX_PERSON];
	for (i = 0; i < f; i++)
	{
		fread(&friends[i], sizeof(friend), 1, fin);
	}
	fclose(fin);
	int id1, id2, found;
	char name1[32], name2[32];
	while (scanf("%s", name1) != EOF)
	{
		if (!strcmp(name1, "end"))
		{
			break;
		}
		scanf("%s", name2);
		for (i = 0, found = 0; i < p, found < 2; i++)
		{
			if (!strcmp(name1, persons[i].name))
			{
				id1 = persons[i].id;
				found++;
			}
			if (!strcmp(name2, persons[i].name))
			{
				id2 = persons[i].id;
				found++;
			}
		}
		for (i = 0, found = 0; i < f; i++)
		{
			if ((id1 == friends[i].id1 && id2 == friends[i].id2) || (id1 == friends[i].id2 && id2 == friends[i].id1))
			{
				printf("yes\n");
				found = 1;
				break;
			}
		}
		if (!found)
		{
			printf("no\n");
		}
	}
	return 0;
}