#ifndef CAR_H

#define CAR_H
#define MAXN 100
typedef struct carstatus
{
	int x, y;
	int g;
} CarStatus;
typedef struct command
{
	int t, v;
} Command;
typedef struct carstatuslist
{
	int num;
	CarStatus status[MAXN];
} CarStatusList;

CarStatusList carSimulation(CarStatus car, Command commands[]);

#endif /* CAR_H */