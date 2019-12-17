#include "heap.h"
void initialize(struct Heap *heap)
{
	heap->num = 0;
	return;
}
int removeMin(struct Heap *heap)
{
	(heap->num)--;
	return heap->array[heap->num];
}
int comp(const void *x, const void *y)
{
	if (*(int *)x > *(int *)y)
	{
		return -1;
	}
	else if (*(int *)x < *(int *)y)
	{
		return 1;
	}
	return 0;
}
void add(struct Heap *heap, int i)
{
	heap->array[heap->num] = i;
	(heap->num)++;
	qsort(heap->array, heap->num, sizeof(heap->array[0]), comp);
	return;
}
int isFull(struct Heap *heap)
{
	return (heap->num == MAXHEAP);
}
int isEmpty(struct Heap *heap)
{
	return (heap->num == 0);
}