#include<stdio.h>

int rec(int tmp[3], int manual[3][3]){
    if (!tmp[0] && !tmp[1] && !tmp[2]){
        printf("yes\n");
        return 1;
    }
    int fl = 0;
    if (tmp[0] >= manual[0][0] && tmp[1] >= manual[0][1] && tmp[2] >= manual[0][2]){
        tmp[0] -= manual[0][0];
        tmp[1] -= manual[0][1];
        tmp[2] -= manual[0][2];
        int fl2 = rec(tmp, manual);
        if (fl2) fl = 1;
        tmp[0] += manual[0][0];
        tmp[1] += manual[0][1];
        tmp[2] += manual[0][2];
    }
    if (tmp[0] >= manual[1][0] && tmp[1] >= manual[1][1] && tmp[2] >= manual[1][2] && !fl){
        tmp[0] -= manual[1][0];
        tmp[1] -= manual[1][1];
        tmp[2] -= manual[1][2];
        int fl2 = rec(tmp, manual);
        if (fl2) fl = 1;
        tmp[0] += manual[1][0];
        tmp[1] += manual[1][1];
        tmp[2] += manual[1][2];
    }
    if (tmp[0] >= manual[2][0] && tmp[1] >= manual[2][1] && tmp[2] >= manual[2][2] && !fl){
        tmp[0] -= manual[2][0];
        tmp[1] -= manual[2][1];
        tmp[2] -= manual[2][2];
        int fl2 = rec(tmp, manual);
        if (fl2) fl = 1;
        tmp[0] += manual[2][0];
        tmp[1] += manual[2][1];
        tmp[2] += manual[2][2];
    }
    return fl;
}

void do_loop(int *n, int manual[3][3]){
    if (*n == 0) return;
    int tmp[3];
    scanf("%d%d%d", &tmp[0], &tmp[1], &tmp[2]);
    if (!rec(tmp, manual)) printf("no\n");
    *n = *n - 1;
    do_loop(n, manual);
    return;
}

int main(){
    int manual[3][3];
    int n;
    scanf("%d%d%d", &manual[0][0], &manual[0][1], &manual[0][2]);
    scanf("%d%d%d", &manual[1][0], &manual[1][1], &manual[1][2]);
    scanf("%d%d%d", &manual[2][0], &manual[2][1], &manual[2][2]);
    scanf("%d", &n);
    do_loop(&n, manual);
    return 0;
}
