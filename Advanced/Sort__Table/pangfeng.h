#ifndef PANGFENG_H

#define PANGFENG_H
typedef struct row
{
	char name[32];
	int score[128];
} Row;
#define MAX_ROW 256
typedef struct examtable
{
	Row rows[MAX_ROW];
	int countRow;
	int dim_n;
} ExamTable;
void init(ExamTable *, int);
void addrow(ExamTable *, char *, int[]);
void print(ExamTable *, int[]);

#endif /* PANGFENG_H */