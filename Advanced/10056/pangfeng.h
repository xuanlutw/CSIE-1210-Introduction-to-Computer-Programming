#ifndef PANGFENG_H
#define PANGFENG_H

typedef struct {
	char sid[32];
	int score[128];
} Row;
typedef struct {
	Row dat[256];
	int dim_n, row_n;
	int sort_order[128];
} ExamTable;

void init(ExamTable *, int);
void addrow(ExamTable *, char *, int[]);
void print(ExamTable *, int[]);

#endif
