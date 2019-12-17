#ifndef HEAP_H

#define HEAP_H
#include <stdlib.h>
#include <string.h>
#define MAXHEAP 100
struct Heap
{
	int array[MAXHEAP];
	int num;
};
void initialize(struct Heap *heap);
int removeMin(struct Heap *heap);
void add(struct Heap *heap, int i);
int isFull(struct Heap *heap);
int isEmpty(struct Heap *heap);

#endif /* HEAP_H */