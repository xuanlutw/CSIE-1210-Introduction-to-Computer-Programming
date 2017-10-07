#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"pangfeng.h"

/*
typedef struct {
	char sid[32];
	int score[128];
} Row;
typedef struct {
	Row dat[256];
	int dim_n, row_n;
	int sort_order[128];
} ExamTable;
*/

void init(ExamTable *et, int n){
    et->row_n = 0;
    et->dim_n = n;
    return;
}

void addrow(ExamTable *et, char *name, int score[]){
    strcpy(et->dat[et->row_n].sid, name);
    for (int i = 0;i < et->dim_n;++i) et->dat[et->row_n].score[i] = score[i];
    ++et->row_n;
    return;
}

int compare(const void* a, const void* b){
    Row ra = *(Row*)a;
    Row rb = *(Row*)b;
    for (int i = 0;i < 128;++i){
        if (ra.score[i] != rb.score[i]) return rb.score[i] - ra.score[i];
    }
    return strcmp(ra.sid, rb.sid);
}

void sort(ExamTable *et){
    Row tmp[256] = {{0},{0}};
    for (int i = 0;i < et->row_n;++i){
        strcpy(tmp[i].sid, et->dat[i].sid);
        for (int j = 0;j < et->dim_n;++j) tmp[i].score[j] = et->dat[i].score[et->sort_order[j]];
    }
    qsort(tmp, et->row_n, sizeof(Row), compare);
    for (int i = 0;i < et->row_n;++i){
        strcpy(et->dat[i].sid, tmp[i].sid);
        for (int j = 0;j < et->dim_n;++j) et->dat[i].score[et->sort_order[j]] = tmp[i].score[j];
    }
    return;
}

void print(ExamTable *et, int order[]){
    printf("----- table begin -----\n");
    for (int i = 0;i < et->dim_n;++i) et->sort_order[i] = order[i];
    sort(et);
    for (int i = 0;i < et->	row_n;++i){
        printf("%s", et->dat[i].sid);
        for (int j = 0;j < et->dim_n;++j) printf(", %d", et->dat[i].score[j]);
        printf("\n");
    }
    printf("----- end         -----\n");
    return;
}
