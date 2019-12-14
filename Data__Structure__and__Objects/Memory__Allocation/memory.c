#include "memory.h"
Memory *getMemory(int start, int length, Memory *next)
{
	Memory *memory = (Memory *)malloc(sizeof(Memory));
	assert(memory != NULL);
	memory->start = start;
	memory->length = length;
	memory->next = next;
	return memory;
}
void initMemory(Memory *memory, int length)
{
	assert(length > 0);
	Memory *new = getMemory(0, length, NULL);
	*memory = (Memory){-1, -1, new};
	assert(memory != NULL);
	return;
}
inline void printMemory(Memory *memory)
{
	assert(memory != NULL);
	Memory *head = memory->next;
	puts("==========");
	while (head != NULL)
	{
		if (head->length != 0)
		{
			printf("start %d, length %d\n", head->start, head->length);
		}
		head = head->next;
	}
	return;
}
void allocateMemory(Memory *memory, int start, int length)
{
	Memory *prev = memory;
	Memory *now = memory->next;
	assert(now != NULL);
	/* 找start在哪一塊記憶體 */
	while ((now != NULL) && (now->start + now->length < start))
	{
		prev = now;
		now = now->next;
	}
	/* 後面那塊沒用到，要自己生 */
	Memory *newmem = getMemory(start + length, (now->start + now->length) - (start + length), now->next);
	now->length = start - now->start;
	now->next = newmem;
	if (newmem->length == 0) //多餘的
	{
		now->next = newmem->next;
		free(newmem);
	}
	if (now->length == 0)
	{
		prev->next = now->next;
		free(now);
	}
	return;
}
void freeMemory(Memory *memory, int start, int length)
{
	Memory *prev = memory;
	Memory *now = memory->next;
	/* 找start在哪一塊記憶體 */
	while ((now != NULL) && (now->start + now->length <= start))
	{
		prev = now;
		now = now->next;
	}
	/* prev->newmem->now */
	Memory *newmem = getMemory(start, length, now);
	prev->next = newmem;
	if (now != NULL && (start + length == now->start))
	{
		newmem->length += now->length;
		newmem->next = now->next;
		free(now);
	}
	if (prev->start + prev->length == newmem->start)
	{
		prev->length += newmem->length;
		prev->next = newmem->next;
		free(newmem);
	}
	return;
}