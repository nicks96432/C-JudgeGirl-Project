#include <stdio.h>
typedef struct Pin
{
	long int left;
	long int right;
	long int probability__up;
	long int probability__down;
} pin;
// 頭尾專用
void reduce(pin *);
// a=b*c
// 頭尾專用 乘完約分
void multiply(pin *, pin *, pin *);
// 中間專用 先約分再乘再約分
void multiply__middle(pin *, pin *, pin *);
long int gcd(long int, long int);
int main(void)
{
	int n;
	scanf("%d", &n);
	int total = n * (n + 1) >> 1, total__new = (n + 1) * (n + 2) >> 1, i, row = 0, column = 1;
	pin pins[total__new];
	pin *iptr, *ptr__left, *ptr__right;
	for (i = 0; i < total; i++)
	{
		scanf("%ld%ld", &pins[i].left, &pins[i].right);
	}
	pins[0].probability__up = 1;
	pins[0].probability__down = 1;
	for (i = 1; i < total__new; i++)
	{
		if (row > column)
		{
			row = 0;
			column++;
#ifdef DEBUG
			printf("\n");
#endif
		}
		if (row == 0)
		{
			pins[i].probability__up = pins[i - column].left;
			pins[i].probability__down = pins[i - column].left + pins[i - column].right;
			iptr = &pins[i];
			ptr__right = &pins[i - column];
			reduce(iptr);
			multiply(iptr, iptr, ptr__right);
		}
		else if (row < column)
		{
			iptr = &pins[i];
			ptr__left = &pins[i - column - 1];
			ptr__right = &pins[i - column];
			multiply__middle(iptr, ptr__left, ptr__right);
		}
		else
		{
			pins[i].probability__up = pins[i - column - 1].right;
			pins[i].probability__down = pins[i - column - 1].left + pins[i - column - 1].right;
			iptr = &pins[i];
			ptr__left = &pins[i - column - 1];
			reduce(iptr);
			multiply(iptr, iptr, ptr__left);
		}
#ifdef DEBUG
		printf("%d ", column);
#endif
		row++;
	}
	for (i = total; i < total__new; i++)
	{
		printf("%ld/%ld\n", pins[i].probability__up, pins[i].probability__down);
	}
	return 0;
}
/*       0
        1 2
       3 4 5
      6 7 8 9

	  	 0
		1 1
	   2 2 2
	  3 3 3 3
*/

void reduce(pin *p)
{
	int Gcd;
	long int tmp1 = p->probability__up, tmp2 = p->probability__down;
	Gcd = gcd(tmp1, tmp2);
	p->probability__up /= Gcd;
	p->probability__down /= Gcd;
	return;
}
void multiply(pin *a, pin *b, pin *c)
{
	long int tmp1up = b->probability__up, tmp1down = b->probability__down;
	long int tmp2up = c->probability__up, tmp2down = c->probability__down;
	long int Gcd1 = gcd(tmp1up, tmp2down), Gcd2 = gcd(tmp2up, tmp1down);
	tmp1up /= Gcd1;
	tmp2up /= Gcd2;
	tmp1down /= Gcd2;
	tmp2down /= Gcd1;
	a->probability__up = tmp1up * tmp2up;
	a->probability__down = tmp1down * tmp2down;
	return;
}
void multiply__middle(pin *a, pin *b, pin *c)
{
	/* 
	 tmp1up	    tmp2up     tmp3up     tmp4up
	-------- * -------- + -------- * --------
	tmp1down   tmp2down   tmp3down   tmp4down
 */

	long int tmp1up = b->probability__up, tmp1down = b->probability__down;
	long int tmp2up = b->right, tmp2down = b->left + b->right;
	long int tmp3up = c->probability__up, tmp3down = c->probability__down;
	long int tmp4up = c->left, tmp4down = c->left + c->right;
	long int Gcd1 = gcd(tmp1up, tmp2down), Gcd2 = gcd(tmp2up, tmp1down);
	long int Gcd3 = gcd(tmp3up, tmp4down), Gcd4 = gcd(tmp4up, tmp3down);
	tmp1up /= Gcd1;
	tmp2up /= Gcd2;
	tmp3up /= Gcd3;
	tmp4up /= Gcd4;
	tmp1down /= Gcd2;
	tmp2down /= Gcd1;
	tmp3down /= Gcd4;
	tmp4down /= Gcd3;
	tmp1up *= tmp2up;
	tmp1down *= tmp2down;
	tmp3up *= tmp4up;
	tmp3down *= tmp4down;
	Gcd1 = gcd(tmp1down, tmp3down);
	tmp1down /= Gcd1;
	tmp3down /= Gcd1;
	tmp1up *= tmp3down;
	tmp3up *= tmp1down;
	tmp1up += tmp3up;
	tmp1down *= tmp3down * Gcd1;
	Gcd1 = gcd(tmp1up, tmp1down);
	tmp1up /= Gcd1;
	tmp1down /= Gcd1;
	a->probability__up = tmp1up;
	a->probability__down = tmp1down;
	return;
}
long int gcd(long int tmp1, long int tmp2)
{
	long int Gcd;
	while (tmp1 != 0 && tmp2 != 0)
	{
		if (tmp1 >= tmp2)
		{
			tmp1 %= tmp2;
		}
		else
		{
			tmp2 %= tmp1;
		}
	}
	if (tmp1 >= tmp2)
	{
		Gcd = tmp1;
	}
	else
	{
		Gcd = tmp2;
	}
	return Gcd;
}