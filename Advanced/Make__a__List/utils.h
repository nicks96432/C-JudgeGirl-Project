#ifndef UTILS_H
#define UTILS_H

int sp_rand();
void sp_srand(long long t);
typedef struct Node
{
	int v;
	struct Node *next;
} Node;
void rm_list(Node *head);
Node *mk_list(int n);

#endif /* UTILS_H */