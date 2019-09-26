#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define NAMELEN 8
#define VAR__MAX 100
#define LINE__MAX 1000
typedef struct Variable
{
	/* 變數名 */
	char name[NAMELEN];
	/* 變數值 */
	int value;
} variable;
typedef struct VariableTable
{
	/* 所有的變數 */
	variable variables[VAR__MAX];
	/* 紀錄變數名稱 */
	char *var__names[VAR__MAX];
} variabletable;
typedef struct Statement
{
	/* 用來儲存指令 */
	int command;
	/* if 用 */
	int comp1, comp2; //運算元
	int operator;	 //運算子
	/* goto 用 */
	int gotoline;
	/* 更改變數的值 & print 用 */
	int target;
} statement;
/* 所有的運算子名稱，要注意這些字代表的是一個數字，不是字串 */
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
/* 所有的指令名稱，要注意這些字代表的是一個數字，不是字串 */
enum statementlist
{
	STOP,
	IF,
	GOTO,
	PRINT,
	ASSIGN /* 更改變數的值 */
};
/* 在 Table 中尋找 String 的位置 */
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
	/* 沒找到 */
	return (-1);
}
/* 在所有變數名稱中透過 find 尋找 name 的位置 */
int find__variable(char *name, variabletable *variables)
{
	int index = find(name, variables->var__names);
	if (index == -1)
	{
		exit(-1);
	}
	return index;
}
/* 在所有運算子中透過 find 尋找 operator 的位置 */
int find__operator(char *name)
{
	/* 所有運算子，一定要照順序排 */
	char *operators[] = {"+", "-", "*", "/", "%", "==", "!=", "<", ">", "<=", ">=", NULL};
	int index = find(name, operators);
	if (index == -1)
	{
		exit(-1);
	}
	return index;
}
/* 讀入變數，注意 variables 是指標 */
void read__variable(variabletable *variables)
{
	/* 記錄這是第幾個變數，初始設定為 0 是因為 END 不能算進去 */
	int count = 0;
	/* 讀入變數名稱用 */
	char name[NAMELEN];
	/* 讀入 = 符號 */
	char assign[NAMELEN];
	/* 透過指標來更改 variables 中的值 */
	variable *varptr;
	/* 讀入變數名稱 */
	scanf("%s", name);
	while (strcmp(name, "END") != 0)
	{
		/* 將 varptr 指向 variables 中的第 count 個變數 */
		varptr = &(variables->variables[count]);
		/* 將讀到的變數名稱存進去 */
		strcpy(varptr->name, name);
		/* 讀入 = 符號 */
		scanf("%s", assign);
		/* 確定讀對了 */
		assert(strcmp(assign, "=") == 0);
		/* 在 variables 紀錄所有的變數名稱 */
		variables->var__names[count] = varptr->name;
		/* 讀入變數的值 */
		scanf("%d", &(varptr->value));
		/* 讀入下一個變數 */
		scanf("%s", name);
		/* 這樣就不會算到 END 了 */
		count++;
	}
}
/* 專門編譯 IF 的函式，注意 variables 是指標 */
void process__if(statement *statementptr, variabletable *variables)
{
	/* 讀入要比較的變數名稱 */
	char comp[NAMELEN];
	/* 讀入比較符號用 */
	char operator[NAMELEN];
	/* IF 一定有一個 GOTO，所以就用這個讀入 */
	char gotostr[NAMELEN];
	scanf("%s", comp);
	statementptr->comp1 = find__variable(comp, variables);
	scanf("%s", operator);
	statementptr->operator= find__operator(operator);
	scanf("%s", comp);
	statementptr->comp2 = find__variable(comp, variables);
	scanf("%s", gotostr);
	/* 確定讀對了 */
	assert(strcmp(gotostr, "GOTO") == 0);
	scanf("%d", &(statementptr->gotoline));
}
/* 專門處理更改變數值的函式，注意 variables 是指標 */
void process__assign(statement *statementptr, char *name, variabletable *variables)
{
	/* 讀入等號右邊的變數名稱用 */
	char comp[NAMELEN];
	/* 讀入等號右邊的運算子用 */
	char operator[NAMELEN];
	/* 讀入 = 符號用 */
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
/* 編譯程式，注意 variables 是指標 */
void process__code(variabletable *variables, statement statements[])
{
	/* 把字串轉換成數字的表格，注意一定要按照原來的順序，更改變數的值沒有指令名稱 */
	char *commands[] = {"STOP", "IF", "GOTO", "PRINT", NULL};
	/* 讀入指令用 */
	char command[NAMELEN];
	/* 印出變數值用 */
	char var__print[NAMELEN];
	/* 把讀到的指令從字串轉成數字用 */
	int type;
	/* 透過指標來更改 statements 的值，由於程式碼從第二行開始，所以指向 1 */
	statement *statementptr = &(statements[1]);
	/* 讀入指令 */
	while (scanf("%s", command) != EOF)
	{
		/* 利用 find 找出指令代表的數字 */
		type = find(command, commands);
		/* 這裡的指令代表的都是數字 */
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
			/* 在 variables 中找到 var__print 是第幾個變數 */
			statementptr->target = find__variable(var__print, variables);
			break;
		/* 更改變數的值 */
		default:
			statementptr->command = ASSIGN;
			/* 這裡的 command 是變數名稱 */
			process__assign(statementptr, command, variables);
			break;
		}
		/* 處理下一條指令 */
		statementptr++;
	}
}
/* 比較全靠這個函式 */
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
/* 算數全靠這個函式 */
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
/* 執行程式，注意 variables 是指標 */
void run__code(variabletable *variables, statement statements[])
{
	/* 第一行是宣告變數，所以程式從第二行開始執行 */
	int line = 1;
	/* 透過指標來更改 statements 的值，由於程式碼從第二行開始，所以指向 1 */
	statement *statementptr = &(statements[line]);
	/* 透過指標來更改 variables 中的值 */
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
/* main 函式 */
int main(void)
{
	variabletable variables;
	statement statements[LINE__MAX];
	/* 讀檔 */
	read__variable(&variables);
	/* 編譯 */
	process__code(&variables, statements);
	/* 執行 */
	run__code(&variables, statements);
	return 0;
}