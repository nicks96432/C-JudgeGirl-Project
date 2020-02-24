#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "reservation.h"
static struct Reservation *generateNode(int nP, int StartTime, int EndTime)
{
	struct Reservation *node = (struct Reservation *)malloc(sizeof(struct Reservation));
	node->StartTime = StartTime;
	node->EndTime = EndTime;
	node->nP = nP;
	node->next = NULL;
	return node;
}
static bool isValid(struct RoomStatus *room, int nP, int StartTime, int EndTime)
{
	struct Reservation *prev = NULL, *ptr = room->reservation;
	while (ptr != NULL)
	{
		if (EndTime <= ptr->StartTime)
		{
			break;
		}
		/* 如果上面那個沒有break就代表 EndTime > ptr->StartTime */
		/* 再加上如果 StartTime < ptr->EndTime 就表示這段時間被用走了 */
		if (StartTime < ptr->EndTime)
		{
			return false;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	struct Reservation *new = generateNode(nP, StartTime, EndTime);
	if (prev == NULL)
	{
		room->reservation = new;
		new->next = ptr;
	}
	else
	{
		prev->next = new;
		new->next = ptr;
	}
	return true;
}
int ReserveRoom(RoomStatus list[], int n, int nP, int StartTime, int EndTime)
{
	for (int i = 0; i < n; i++)
	{
		if (list[i].capacity >= nP && isValid(&(list[i]), nP, StartTime, EndTime))
		{
			return 1;
		}
	}
	return 0;
}