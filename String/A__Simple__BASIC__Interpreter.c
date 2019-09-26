#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define NAMELEN 8
#define VAR__MAX 100
#define LINE__MAX 1000
typedef struct Variable
{
	/* �ܼƦW */
	char name[NAMELEN];
	/* �ܼƭ� */
	int value;
} variable;
typedef struct VariableTable
{
	/* �Ҧ����ܼ� */
	variable variables[VAR__MAX];
	/* �����ܼƦW�� */
	char *var__names[VAR__MAX];
} variabletable;
typedef struct Statement
{
	/* �Ψ��x�s���O */
	int command;
	/* if �� */
	int comp1, comp2; //�B�⤸
	int operator;	 //�B��l
	/* goto �� */
	int gotoline;
	/* ����ܼƪ��� & print �� */
	int target;
} statement;
/* �Ҧ����B��l�W�١A�n�`�N�o�Ǧr�N���O�@�ӼƦr�A���O�r�� */
enum operatorlist
{
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	EQL,
	NOTEQL,
	SMALLER,
	LARGER,
	SMALLEREQL,
	LARGEREQL
};
/* �Ҧ������O�W�١A�n�`�N�o�Ǧr�N���O�@�ӼƦr�A���O�r�� */
enum statementlist
{
	STOP,
	IF,
	GOTO,
	PRINT,
	ASSIGN /* ����ܼƪ��� */
};
/* �b Table ���M�� String ����m */
int find(char *string, char *table[])
{
	int index = 0;
	while (table[index] != NULL)
	{
		if (strcmp(string, table[index]) == 0)
		{
			return index;
		}
		index++;
	}
	/* �S��� */
	return (-1);
}
/* �b�Ҧ��ܼƦW�٤��z�L find �M�� name ����m */
int find__variable(char *name, variabletable *variables)
{
	int index = find(name, variables->var__names);
	if (index == -1)
	{
		exit(-1);
	}
	return index;
}
/* �b�Ҧ��B��l���z�L find �M�� operator ����m */
int find__operator(char *name)
{
	/* �Ҧ��B��l�A�@�w�n�Ӷ��Ǳ� */
	char *operators[] = {"+", "-", "*", "/", "%", "==", "!=", "<", ">", "<=", ">=", NULL};
	int index = find(name, operators);
	if (index == -1)
	{
		exit(-1);
	}
	return index;
}
/* Ū�J�ܼơA�`�N variables �O���� */
void read__variable(variabletable *variables)
{
	/* �O���o�O�ĴX���ܼơA��l�]�w�� 0 �O�]�� END �����i�h */
	int count = 0;
	/* Ū�J�ܼƦW�٥� */
	char name[NAMELEN];
	/* Ū�J = �Ÿ� */
	char assign[NAMELEN];
	/* �z�L���Шӧ�� variables ������ */
	variable *varptr;
	/* Ū�J�ܼƦW�� */
	scanf("%s", name);
	while (strcmp(name, "END") != 0)
	{
		/* �N varptr ���V variables ������ count ���ܼ� */
		varptr = &(variables->variables[count]);
		/* �NŪ�쪺�ܼƦW�٦s�i�h */
		strcpy(varptr->name, name);
		/* Ū�J = �Ÿ� */
		scanf("%s", assign);
		/* �T�wŪ��F */
		assert(strcmp(assign, "=") == 0);
		/* �b variables �����Ҧ����ܼƦW�� */
		variables->var__names[count] = varptr->name;
		/* Ū�J�ܼƪ��� */
		scanf("%d", &(varptr->value));
		/* Ū�J�U�@���ܼ� */
		scanf("%s", name);
		/* �o�˴N���|��� END �F */
		count++;
	}
}
/* �M���sĶ IF ���禡�A�`�N variables �O���� */
void process__if(statement *statementptr, variabletable *variables)
{
	/* Ū�J�n������ܼƦW�� */
	char comp[NAMELEN];
	/* Ū�J����Ÿ��� */
	char operator[NAMELEN];
	/* IF �@�w���@�� GOTO�A�ҥH�N�γo��Ū�J */
	char gotostr[NAMELEN];
	scanf("%s", comp);
	statementptr->comp1 = find__variable(comp, variables);
	scanf("%s", operator);
	statementptr->operator= find__operator(operator);
	scanf("%s", comp);
	statementptr->comp2 = find__variable(comp, variables);
	scanf("%s", gotostr);
	/* �T�wŪ��F */
	assert(strcmp(gotostr, "GOTO") == 0);
	scanf("%d", &(statementptr->gotoline));
}
/* �M���B�z����ܼƭȪ��禡�A�`�N variables �O���� */
void process__assign(statement *statementptr, char *name, variabletable *variables)
{
	/* Ū�J�����k�䪺�ܼƦW�٥� */
	char comp[NAMELEN];
	/* Ū�J�����k�䪺�B��l�� */
	char operator[NAMELEN];
	/* Ū�J = �Ÿ��� */
	char assign[NAMELEN];
	statementptr->target = find__variable(name, variables);
	scanf("%s", assign);
	assert(strcmp(assign, "=") == 0);
	scanf("%s", comp);
	statementptr->comp1 = find__variable(comp, variables);
	scanf("%s", operator);
	statementptr->operator= find__operator(operator);
	scanf("%s", comp);
	statementptr->comp2 = find__variable(comp, variables);
}
/* �sĶ�{���A�`�N variables �O���� */
void process__code(variabletable *variables, statement statements[])
{
	/* ��r���ഫ���Ʀr�����A�`�N�@�w�n���ӭ�Ӫ����ǡA����ܼƪ��ȨS�����O�W�� */
	char *commands[] = {"STOP", "IF", "GOTO", "PRINT", NULL};
	/* Ū�J���O�� */
	char command[NAMELEN];
	/* �L�X�ܼƭȥ� */
	char var__print[NAMELEN];
	/* ��Ū�쪺���O�q�r���ন�Ʀr�� */
	int type;
	/* �z�L���Шӧ�� statements ���ȡA�ѩ�{���X�q�ĤG��}�l�A�ҥH���V 1 */
	statement *statementptr = &(statements[1]);
	/* Ū�J���O */
	while (scanf("%s", command) != EOF)
	{
		/* �Q�� find ��X���O�N���Ʀr */
		type = find(command, commands);
		/* �o�̪����O�N�����O�Ʀr */
		switch (type)
		{
		case GOTO:
			statementptr->command = GOTO;
			scanf("%d", &(statementptr->gotoline));
			break;
		case STOP:
			statementptr->command = STOP;
			break;
		case IF:
			statementptr->command = IF;
			process__if(statementptr, variables);
			break;
		case PRINT:
			statementptr->command = PRINT;
			scanf("%s", var__print);
			/* �b variables ����� var__print �O�ĴX���ܼ� */
			statementptr->target = find__variable(var__print, variables);
			break;
		/* ����ܼƪ��� */
		default:
			statementptr->command = ASSIGN;
			/* �o�̪� command �O�ܼƦW�� */
			process__assign(statementptr, command, variables);
			break;
		}
		/* �B�z�U�@�����O */
		statementptr++;
	}
}
/* ������a�o�Ө禡 */
int compare(int comp1, int comp2, int operator)
{
	switch (operator)
	{
	case EQL:
		return (comp1 == comp2);
		break;
	case NOTEQL:
		return (comp1 != comp2);
		break;
	case SMALLER:
		return (comp1 < comp2);
		break;
	case LARGER:
		return (comp1 > comp2);
		break;
	case SMALLEREQL:
		return (comp1 <= comp2);
		break;
	case LARGEREQL:
		return (comp1 >= comp2);
		break;
	default:
		printf("invalid operator%d\n", operator);
		exit(-1);
		break;
	}
}
/* ��ƥ��a�o�Ө禡 */
int math(int comp1, int comp2, int operator)
{
	switch (operator)
	{
	case ADD:
		return (comp1 + comp2);
		break;
	case SUB:
		return (comp1 - comp2);
		break;
	case MUL:
		return (comp1 * comp2);
		break;
	case DIV:
		return (comp1 / comp2);
		break;
	case MOD:
		return (comp1 % comp2);
		break;
	default:
		printf("invalid operator%d\n", operator);
		break;
	}
}
/* ����{���A�`�N variables �O���� */
void run__code(variabletable *variables, statement statements[])
{
	/* �Ĥ@��O�ŧi�ܼơA�ҥH�{���q�ĤG��}�l���� */
	int line = 1;
	/* �z�L���Шӧ�� statements ���ȡA�ѩ�{���X�q�ĤG��}�l�A�ҥH���V 1 */
	statement *statementptr = &(statements[line]);
	/* �z�L���Шӧ�� variables ������ */
	variable *varptr = variables->variables;
	while (statementptr->command != STOP)
	{
		switch (statementptr->command)
		{
		case IF:
			if (compare(varptr[statementptr->comp1].value, varptr[statementptr->comp2].value, statementptr->operator))
			{
				line = statementptr->gotoline;
			}
			else
			{
				line++;
			}
			break;
		case GOTO:
			line = statementptr->gotoline;
			break;
		case ASSIGN:
			varptr[statementptr->target].value = math(varptr[statementptr->comp1].value, varptr[statementptr->comp2].value, statementptr->operator);
			line++;
			break;
		case PRINT:
			printf("%d\n", varptr[statementptr->target].value);
			line++;
			break;
		default:
			printf("invalid code %d\n", statementptr->command);
			exit(-1);
			break;
		}
		statementptr = &(statements[line]);
	}
}
/* main �禡 */
int main(void)
{
	variabletable variables;
	statement statements[LINE__MAX];
	/* Ū�� */
	read__variable(&variables);
	/* �sĶ */
	process__code(&variables, statements);
	/* ���� */
	run__code(&variables, statements);
	return 0;
}