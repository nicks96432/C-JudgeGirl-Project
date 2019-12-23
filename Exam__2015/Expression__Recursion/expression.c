#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "expression.h"
static int error = 0;
int expressionEval(char *string, int *length)
{
	if (isdigit(*(string + (*length))))
	{
		(*length)++;
		return *(string + (*length) - 1) - '0';
	}
	else if ((*(string + *length)) == '(')
	{
		(*length)++;
		int left = expressionEval(string, length);
		char operator;
		sscanf(string + (*length), "%c", &operator);
		(*length)++;
		int right = expressionEval(string, length);
		(*length)++;
		switch (operator)
		{
		case '+':
			return left + right;
			break;
		case '-':
			return left - right;
			break;
		case '*':
			return left * right;
			break;
		case '/':
			if (right == 0)
			{
				error = 1;
				return 0;
			}
			else
			{
				return left / right;
			}
			break;
		default:
			error = 1;
			break;
		}
	}
	else if ((*(string + *length)) == '-')
	{
		(*length)++;
		return (-1) * expressionEval(string, length);
	}
}
int expression(char *string)
{
	int ans = 0;
	int length = 0;
	ans = expressionEval(string, &length);
	if (error)
	{
		return -0x80000000;
	}
	else
	{
		return ans;
	}
}