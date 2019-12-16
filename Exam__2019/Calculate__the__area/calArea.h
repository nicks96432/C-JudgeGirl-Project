#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	struct node *rightPtr;
	struct node *downPtr;
} NODE;
int calArea(NODE *head);