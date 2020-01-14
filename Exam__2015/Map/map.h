#ifndef MAP_H

#define MAP_H
#define MAX_PAIR 1024
typedef struct _Pair
{
	int key;
	char value[128];
} Pair;
typedef struct _Map
{
	Pair pairs[MAX_PAIR];
	int countPair;
} Map;
void init(Map *map);
int map(Map *map, const int key, const char *value);
int numPairs(Map *map);
void print(Map *map);
const char *getValue(Map *map, const int key);
int unmap(Map *map, const int key);
int reverseMap(Map *map, const char *value, int keys[]);

#endif /* MAP_H */