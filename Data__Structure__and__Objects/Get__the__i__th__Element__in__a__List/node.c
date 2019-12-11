#include <stdio.h>
#include "node.h"
struct node *getNode(struct node *head, unsigned int i)
{
	unsigned int count = 0;
	head->prev = NULL;
	while (head->next != NULL)
	{
		(head->next)->prev = head;
		head = head->next;
		count++;
	}
	if (i > count)
	{
		return NULL;
	}
	while (head->prev != NULL && i > 0)
	{
		head = head->prev;
		i--;
	}
	return head;
}