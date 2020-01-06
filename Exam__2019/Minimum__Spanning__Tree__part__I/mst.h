#ifndef MST_H

#define MST_H
#include <stdbool.h>
#define MAX_N 10
typedef struct mst
{
	int N;
	int road[MAX_N][MAX_N];
} MST;
void init(MST *mst, int N);
void addRoad(MST *mst, int city1, int city2, int len);
int removeRoad(MST *mst, int city1, int city2);
bool hasPath(MST *mst, int city1, int city2);
bool connected(MST *mst);

#endif /* MST_H */