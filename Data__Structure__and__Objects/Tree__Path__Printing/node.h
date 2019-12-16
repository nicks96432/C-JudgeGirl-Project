#ifndef NODE_H
#define NODE_H

struct node
{
	struct node *left;
	struct node *right;
	int data;
};
typedef struct node Node;
void print_all_paths(struct node *root);

#endif /* NODE_H */