#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_M 10000
typedef struct _graph
{
	int roads[MAX_M * 2][2];
	int countRoad;
} Graph;
typedef struct _map
{
	int name[MAX_M * 2];
	int *pointer[MAX_M * 2];
	bool visited[MAX_M * 2];
	int countCity;
} Map;
void init(Graph *graph)
{
	graph->countRoad = 0;
}
void addRoad(Graph *graph, int city1, int city2)
{
	graph->roads[graph->countRoad][0] = city1;
	graph->roads[graph->countRoad][1] = city2;
	graph->countRoad++;
	graph->roads[graph->countRoad][0] = city2;
	graph->roads[graph->countRoad][1] = city1;
	graph->countRoad++;
	return;
}
int comp(const void *x, const void *y)
{
	if (*(int *)x > *(int *)y)
	{
		return 1;
	}
	else if (*(int *)x < *(int *)y)
	{
		return -1;
	}
	return 0;
}
void normalized(Graph *graph, Map *map)
{
	qsort(graph->roads, graph->countRoad, sizeof(int) * 2, comp);
	map->countCity = 0;
	int prev = -1;
	for (int i = 0; i < graph->countRoad; i++)
	{
		if (graph->roads[i][0] != prev)
		{
			map->name[map->countCity] = graph->roads[i][0];
			map->pointer[map->countCity] = graph->roads[i];
			map->visited[map->countCity] = false;
			map->countCity++;
			prev = graph->roads[i][0];
		}
	}
	return;
}
int findCity(Map *map, int city)
{
	int *find = (int *)bsearch(&city, map->name, map->countCity, sizeof(int), comp);
	if (!find)
	{
		return -1;
	}
	return (int)(find - map->name);
}
bool hasPath(Graph *graph, Map *map, int city1, int city2)
{
	if (city1 == city2)
	{
		return true;
	}
	int findCity1 = findCity(map, city1);
	int i = (int)(map->pointer[findCity1] - graph->roads[0]) / 2;
	while (i < graph->countRoad && graph->roads[i][0] == city1)
	{
		int next = graph->roads[i][1];
		if (!map->visited[next])
		{
			map->visited[next] = true;
			if (hasPath(graph, map, next, city2))
			{
				return true;
			}
		}
		i++;
	}
	return false;
}
int main(void)
{
	int m;
	Graph graph;
	Map map;
	init(&graph);
	scanf("%d", &m);
	int i,j, city1, city2;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &city1, &city2);
		addRoad(&graph, city1, city2);
	}
	normalized(&graph, &map);
	int q;
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d%d", &city1, &city2);
		if (findCity(&map, city1) == -1 || findCity(&map, city2) == -1)
		{
			puts("There is no path.");
		}
		else
		{
			for (j = 0; j < MAX_M * 2; j++)
			{
				map.visited[j] = false;
			}
			if (hasPath(&graph, &map, city1, city2))
			{
				puts("There is a path.");
			}
			else
			{
				puts("There is no path.");
			}
		}
	}
	return 0;
}