#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int year;
    char month;
    char day;
}Date;

int compare(const void* a, const void* b){
    Date da = *(Date*)a;
    Date db = *(Date*)b;
    if (da.year != db.year) return da.year - db.year;
    if (da.month != db.month) return da.month - db.month;
    if (da.day != db.day) return da.day - db.day;
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    Date dd[n];
    for (int i = 0;i < n;++i) scanf("%d%d%d", &dd[i].year, &dd[i].month, &dd[i].day);
    qsort(dd, n, sizeof(Date), compare);
    for (int i = 0;i < n;++i) printf("%d %d %d\n", dd[i].year, dd[i].month, dd[i].day);
    return 0;
} 
