#ifndef ARRAY_H

#define ARRAY_H
#define MAX_ARRAY 2048
typedef struct _ARRAY
{
	int start;
	int end;
	int value[MAX_ARRAY];
} ARRAY;
void init(ARRAY *darray, int startIndex, int endIndex);
int set(ARRAY *array, int index, int value);
int get(ARRAY *array, int index);
void print(ARRAY *array);
void sort(ARRAY *array);

#endif /* ARRAY_H */