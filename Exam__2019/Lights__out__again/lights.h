#ifndef LIGHTS_H
#define LIGHTS_H

#include <stdbool.h>
#define MAX_N 4
typedef struct _lights
{
	bool isPressed[MAX_N * MAX_N];
	bool isOpen[MAX_N * MAX_N];
	int pressedNum[MAX_N * MAX_N];
	int countLights;
	int countFlip;
} Lights;
void init(Lights *l);
int numOfLights(Lights *l, int N);
void flip(Lights *l, int i, int N);
void printLights(Lights *l, int N);

#endif /* LIGHTS_H */