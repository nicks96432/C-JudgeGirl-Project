#ifndef NODE_H
#define NODE_H

struct node
{
	int value;
	struct node *next;
};
struct node *merge(struct node *, struct node *);

#endif /* NODE_H */