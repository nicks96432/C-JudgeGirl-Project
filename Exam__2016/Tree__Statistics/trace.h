#ifndef TRACE_H

#define TRACE_H
typedef struct Node
{
	struct ChildList *list;
} Node;
typedef struct ChildList
{
	Node *node;
	struct ChildList *next;
} ChildList;
typedef struct Answer
{
	int InternalNode;
	int Leaf;
	int MaxBranchFactor;
	int Depth;
} Answer;
void trace(Node *root, Answer *ans);

#endif /* TRACE_H */