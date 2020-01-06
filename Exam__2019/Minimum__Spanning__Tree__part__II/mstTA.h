#ifndef MSTTA_H

#define MSTTA_H
#include <stdbool.h>
#define MAX_N 10
typedef struct mstTA
{
	int N;
	int road[MAX_N][MAX_N];
} MSTTA;
void initTA(MSTTA *mst, int N);
void addRoadTA(MSTTA *mst, int city1, int city2, int len);
int removeRoadTA(MSTTA *mst, int city1, int city2);
bool hasPathTA(MSTTA *mst, int city1, int city2);
bool connectedTA(MSTTA *mst);

#endif /* MSTTA_H */