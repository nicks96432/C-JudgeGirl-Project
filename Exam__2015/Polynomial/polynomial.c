#include <stdio.h>
#include "polynomial.h"
void init(Polynomial *poly, int coefficient[], int n)
{
	int i;
	poly->count = n;
	for (i = 0; i < n; i++)
	{
		poly->coefficient[i] = coefficient[i];
	}
	for (; i < MAX_COEFFICIENT; i++)
	{
		poly->coefficient[i] = 0;
	}
	return;
}
Polynomial add(Polynomial *poly1, Polynomial *poly2)
{
	Polynomial sum;
	sum.count = poly1->count > poly2->count ? poly1->count : poly2->count;
	for (int i = 0; i < sum.count; i++)
	{
		sum.coefficient[i] = poly1->coefficient[i] + poly2->coefficient[i];
	}
	return sum;
}
Polynomial multiply(Polynomial *poly1, Polynomial *poly2)
{
	Polynomial mul;
	init(&mul, NULL, 0);
	mul.count = poly1->count + poly2->count;
	for (int i = 0; i < poly1->count; i++)
	{
		for (int j = 0; j < poly2->count; j++)
		{
			mul.coefficient[i + j] += poly1->coefficient[i] * poly2->coefficient[j];
		}
	}
	return mul;
}
void print(Polynomial *poly)
{
	for (int i = poly->count - 1; i >= 2; i--)
	{
		if (poly->coefficient[i] != 0)
		{
			printf("%+dx^%d", poly->coefficient[i], i);
		}
	}
	if (poly->coefficient[1] != 0)
	{
		printf("%+dx", poly->coefficient[1]);
	}
	if (poly->coefficient[0] != 0)
	{
		printf("%+d\n", poly->coefficient[0]);
	}
	else
	{
		printf("\n");
	}
	return;
}