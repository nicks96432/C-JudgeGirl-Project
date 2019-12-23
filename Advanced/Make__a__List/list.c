/* 這題用遞迴會爆掉 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utils.h"
Node *generateNode(void)
{
	Node *newnode = malloc(sizeof(Node));
	assert(newnode != NULL);
	newnode->v = sp_rand();
	newnode->next = NULL;
	return newnode;
}
Node *mk_list(int n)
{
	if (n == 0)
	{
		return NULL;
	}
	Node *head = generateNode();
	Node *now = head;
	for (int i = 1; i < n; i++)
	{
		now->next = generateNode();
		now = now->next;
	}
	return head;
}
void rm_list(Node *head)
{
	Node *now = head, *prev = NULL;
	while (now)
	{
		prev = now;
		now = now->next;
		free(prev);
	}
	return;
}
