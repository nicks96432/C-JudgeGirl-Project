#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "node.h"
#define LEN 1000
struct node *build(int v[], int n)
{
	struct node *head, *ptr;
	int i;
	if (!n)
	{
		return NULL;
	}
	head = (struct node *)malloc(sizeof(struct node));
	assert(head != NULL);
	ptr = head;
	head->value = v[0];
	for (i = 1; i < n; i++)
	{
		ptr->next = (struct node *)malloc(sizeof(struct node));
		assert(ptr->next != NULL);
		ptr = ptr->next;
		ptr->value = v[i];
	}
	ptr->next = 0;
	return head;
}
void print(struct node *ptr)
{
	printf("%d", ptr->value);
	if (ptr->next)
	{
		putchar(' ');
		print(ptr->next);
	}
}
int main(void)
{
	int n1, n2;
	int v1[LEN], v2[LEN];
	int i;
	struct node *list1, *list2;
	scanf("%d", &n1);
	for (i = 0; i < n1; i++)
	{
		scanf("%d", &v1[i]);
	}
	scanf("%d", &n2);
	for (i = 0; i < n2; i++)
	{
		scanf("%d", &v2[i]);
	}
	list1 = build(v1, n1);
	list2 = build(v2, n2);
	print(merge(list1, list2));
	putchar('\n');
	return 0;
}