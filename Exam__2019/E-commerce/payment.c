#include <stdio.h>
#include <stdbool.h>
#include "payment.h"
int findID(int itemID[], int ID)
{
	int i;
	for (i = 0;; i++)
	{
		if (itemID[i] == 0)
		{
			return -1;
		}
		if (ID == itemID[i])
		{
			return i;
		}
	}
}
bool findsale(int onSaleItemID[], int ID)
{
	int i;
	for (i = 0;; i++)
	{
		if (onSaleItemID[i] == 0)
		{
			return false;
		}
		if (ID == onSaleItemID[i])
		{
			return true;
		}
	}
}
double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[])
{
	int i, ID, index;
	double ans = 0;
	for (i = 0;; i++)
	{
		if (orderItemID[i] == 0)
		{
			break;
		}
		index = findID(itemID, orderItemID[i]);
		if (index == -1)
		{
			continue;
		}
		ID = itemID[index];
		if (!findsale(onSaleItemID, ID))
		{
			ans += price[index] * orderQuantity[i];
		}
		else
		{
			ans += price[index] * orderQuantity[i] * 0.8;
		}
	}
	if (ans < 490.00)
	{
		ans += 80;
	}
	return ans;
}