#ifndef LOCKER_H

#define LOCKER_H
#include <stdbool.h>
typedef struct _Lock
{
	bool locked;
	int password;
} Lock;
void init(Lock *lock);
int lock(Lock *lock, int combination);
int unlock(Lock *lock, int combination);
int isLocked(Lock *lock);

#endif /* LOCKER_H */