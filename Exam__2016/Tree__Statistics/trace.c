#include <stdio.h>
#include "trace.h"
static int depth = -1;
void trace(Node *root, Answer *ans)
{
	if (root == NULL)
	{
		return;
	}
	int countChild = 0;
	ChildList *ptr = root->list;
	depth++;
	if (root->list == NULL)
	{
		ans->Leaf++;
	}
	else
	{
		ans->InternalNode++;
	}
	while (ptr != NULL)
	{
		trace(ptr->node, ans);
		ptr = ptr->next;
		countChild++;
	}
	if (countChild > ans->MaxBranchFactor)
	{
		ans->MaxBranchFactor = countChild;
	}
	if (depth > ans->Depth)
	{
		ans->Depth = depth;
	}
	depth--;
	return;
}