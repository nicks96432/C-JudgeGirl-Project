#ifndef SUB_H

#define SUB_H
typedef struct Node
{
	char c;
	struct Node *next;
} Node;
void substring(Node *text, Node *pattern);
void subsequence(Node *text, Node *pattern);

#endif /* SUB_H */