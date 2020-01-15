#include <stdbool.h>
#include "locker.h"
void init(Lock *lock)
{
	lock->locked = false;
	return;
}
int lock(Lock *lock, int combination)
{
	if (lock->locked)
	{
		return -1;
	}
	if (combination > 9999 || combination < 0)
	{
		return 10000;
	}
	lock->locked = true;
	lock->password = combination;
	return combination;
}
int unlock(Lock *lock, int combination)
{
	if (lock->locked == false)
	{
		return -1;
	}
	if (lock->password != combination)
	{
		return 1;
	}
	lock->locked = false;
	return 0;
}
int isLocked(Lock *lock)
{
	return lock->locked ? 1 : 0;
}