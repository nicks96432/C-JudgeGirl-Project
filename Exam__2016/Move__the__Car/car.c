#include <stdbool.h>
#include "car.h"
CarStatusList carSimulation(CarStatus car, Command commands[])
{
	CarStatusList answer;
	answer.num = 0;
	bool stop = false;
	/* 0:停 1:加油 2:右 3:左 4:上 5:下 */
	for (int i = 0; !stop; i++)
	{
		switch (commands[i].t)
		{
		case 0:
			stop = true;
			break;
		case 1:
			car.g += commands[i].v;
			break;
		case 2:
			if (car.g >= commands[i].v)
			{
				car.g -= commands[i].v;
				car.x += commands[i].v;
				answer.status[answer.num].x = car.x;
				answer.status[answer.num].y = car.y;
				answer.status[answer.num].g = car.g;
				answer.num++;
			}
			else
			{
				stop = true;
			}
			break;
		case 3:
			if (car.g >= commands[i].v)
			{
				car.g -= commands[i].v;
				car.x -= commands[i].v;
				answer.status[answer.num].x = car.x;
				answer.status[answer.num].y = car.y;
				answer.status[answer.num].g = car.g;
				answer.num++;
			}
			else
			{
				stop = true;
			}
			break;
		case 4:
			if (car.g >= commands[i].v)
			{
				car.g -= commands[i].v;
				car.y += commands[i].v;
				answer.status[answer.num].x = car.x;
				answer.status[answer.num].y = car.y;
				answer.status[answer.num].g = car.g;
				answer.num++;
			}
			else
			{
				stop = true;
			}
			break;
		case 5:
			if (car.g >= commands[i].v)
			{
				car.g -= commands[i].v;
				car.y -= commands[i].v;
				answer.status[answer.num].x = car.x;
				answer.status[answer.num].y = car.y;
				answer.status[answer.num].g = car.g;
				answer.num++;
			}
			else
			{
				stop = true;
			}
			break;
		default:
			stop = true;
			break;
		}
	}
	return answer;
}