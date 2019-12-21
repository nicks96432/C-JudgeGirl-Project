#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Student
{
	char name[64];
	struct Student *left, *right;
} student;
typedef struct Club
{
	char name[64];
	student *findRoot;
	struct Club *left, *right;
} club;
student *generateStudent(char *studentName)
{
	student *newStudent = (student *)malloc(sizeof(student));
	assert(newStudent != NULL);
	strcpy(newStudent->name, studentName);
	newStudent->left = NULL;
	newStudent->right = NULL;
	return newStudent;
}
club *generateClub(char *clubName, char *leaderName)
{
	club *newClub = (club *)malloc(sizeof(club));
	newClub->findRoot = generateStudent(leaderName);
	strcpy(newClub->name, clubName);
	newClub->left = NULL;
	newClub->right = NULL;
	return newClub;
}
student *insertStudent(student *root, char *studentName)
{
	if (root == NULL)
	{
		return generateStudent(studentName);
	}
	if (strcmp(root->name, studentName) < 0)
	{
		root->left = insertStudent(root->left, studentName);
	}
	else
	{
		root->right = insertStudent(root->right, studentName);
	}
	return root;
}
club *createClub(club *root, char *clubName, char *studentName)
{
	if (root == NULL)
	{
		return generateClub(clubName, studentName);
	}
	else if (strcmp(root->name, clubName) < 0)
	{
		root->left = createClub(root->left, clubName, studentName);
	}
	else if (strcmp(root->name, clubName) > 0)
	{
		root->right = createClub(root->right, clubName, studentName);
	}
	else
	{
		root->findRoot = insertStudent(root->findRoot, studentName);
	}
	return root;
}
int findStudent(student *root, char *studentName)
{
	if (root == NULL)
	{
		return 0;
	}
	if (strcmp(root->name, studentName) > 0)
	{
		return findStudent(root->right, studentName);
	}
	else if (strcmp(root->name, studentName) < 0)
	{
		return findStudent(root->left, studentName);
	}
	else
	{
		return 1;
	}
}
club *findClub(club *root, char *clubName)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (strcmp(root->name, clubName) < 0)
	{
		return findClub(root->left, clubName);
	}
	else if (strcmp(root->name, clubName) > 0)
	{
		return findClub(root->right, clubName);
	}
	else
	{
		return root;
	}
}
void freeStudent(student *root)
{
	if (root == NULL)
	{
		return;
	}
	freeStudent(root->left);
	freeStudent(root->right);
	free(root);
	return;
}
void freeClub(club *root)
{
	if (root == NULL)
	{
		return;
	}
	freeClub(root->left);
	freeClub(root->right);
	freeStudent(root->findRoot);
	return;
}
int main(void)
{
	int K;
	scanf("%d", &K);
	club *clubs = NULL;
	int type;
	char studentName[64], clubName[64];
	int i, j;
	for (i = 0; i < K; i++)
	{
		scanf("%d%s%s", &type, studentName, clubName);
		clubs = createClub(clubs, clubName, studentName);
	}
	int q;
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &type);
		if (type == 0)
		{
			scanf("%s", clubName);
			club *find = findClub(clubs, clubName);
			if (find == NULL)
			{
				puts("None");
			}
			else
			{
				printf("%s\n", find->findRoot->name);
			}
		}
		else if (type == 1)
		{
			scanf("%s %s", studentName, clubName);
			club *find = findClub(clubs, clubName);
			if (find == NULL)
			{
				puts("-1");
			}
			else
			{
				printf("%d\n", findStudent(find->findRoot, studentName));
			}
		}
		else
		{
			assert(0);
		}
	}
	freeClub(clubs);
	return 0;
}