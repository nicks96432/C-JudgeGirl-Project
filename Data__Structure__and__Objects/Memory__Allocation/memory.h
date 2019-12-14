#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef struct mem
{
	int start;
	int length;
	struct mem *next;
} Memory;
void initMemory(Memory *memory, int length);
void printMemory(Memory *memory);
void allocateMemory(Memory *memory, int start, int length);
void freeMemory(Memory *memory, int start, int length);

#endif /* MEMORY_H */
