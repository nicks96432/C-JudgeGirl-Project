#ifndef NODE_H
#define NODE_H

struct node
{
	struct node *next;
	struct node *prev;
};
struct node *getNode(struct node *head, unsigned int i);
#endif /* NODE_H */