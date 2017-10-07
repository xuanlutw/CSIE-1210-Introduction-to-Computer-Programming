#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int year;
    int month;
    int day;
    char category[32];
    int expense;
}Expense;

int compare(const void* a, const void* b){
    Expense ea = *(Expense*)a;
    Expense eb = *(Expense*)b;
    if (ea.year != eb.year) return ea.year - eb.year;
    if (ea.month != eb.month) return ea.month - eb.month;
    if (ea.day != eb.day) return ea.day - eb.day;
    return strcmp(ea.category, eb.category);
}

int main(){
    Expense exp[10000];
    int n;
    for (n = 0;scanf("%d%d%d%s%d", &exp[n].year, &exp[n].month, &exp[n].day, exp[n].category, &exp[n].expense) != EOF;++n);
    qsort(exp, n, sizeof(Expense), compare);
    Expense tmp;
    tmp = exp[0];
    for (int i = 1;i < n;++i){
        if (tmp.year == exp[i].year && tmp.month == exp[i].month && tmp.day == exp[i].day && !strcmp(tmp.category, exp[i].category)) tmp.expense += exp[i].expense;
        else{
            printf("%d %d %d %s %d\n", tmp.year, tmp.month, tmp.day, tmp.category, tmp.expense);
            tmp = exp[i];
        }
    }
    printf("%d %d %d %s %d\n", tmp.year, tmp.month, tmp.day, tmp.category, tmp.expense);
    return 0;
}	
