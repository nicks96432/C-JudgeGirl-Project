#ifndef LOCK_H
#define LOCK_H
typedef struct _lock
{
	int trigger[3];
}lock;
typedef struct locks 
{
	lock Lock[100];
	int countLock;
} Locks;
 
Locks* init(int lockSeq[][3], int n);
 
int numUnlocked(Locks *locks, bool lights[], int m);
#endif /* LOCK_H */