#include<stdio.h>

void first(int ptf, int pts, int now, int n, int map[4][4], int* fir, int* equ, int* sec);
void second(int ptf, int pts, int now, int n, int map[4][4], int* fir, int* equ, int* sec);

void second(int ptf, int pts, int now, int n, int map[4][4], int* fir, int* equ, int* sec){
    int fl = 1;
    for (int i = 0;i < n;++i){
        if (!map[i][now]) continue;
        int tmp = map[i][now];
        map[i][now] = 0;
        first(ptf, pts + tmp, i, n, map, fir, equ, sec);
        map[i][now] = tmp;
        fl = 0;
    }
    if (fl){
        if (ptf > pts) ++(*fir); 
        if (ptf < pts) ++(*sec); 
        if (ptf == pts) ++(*equ);
    }
    return;
}

void first(int ptf, int pts, int now, int n, int map[4][4], int* fir, int* equ, int* sec){
    int fl = 1;
    for (int i = 0;i < n;++i){
        if (!map[now][i]) continue;
        int tmp = map[now][i];
        map[now][i] = 0;
        second(ptf + tmp, pts, i, n, map, fir, equ, sec);
        map[now][i] = tmp;
        fl = 0;
    }
    if (fl){
        if (ptf > pts) ++(*fir); 
        if (ptf < pts) ++(*sec); 
        if (ptf == pts) ++(*equ);
    }
    return;
}
 
int main(){
    int n, map[4][4];
    while(scanf("%d", &n) != EOF){
        for (int i = 0;i < n;++i){
            for (int j = 0;j < n;++j) scanf("%d", &map[i][j]);
        }
	int fir = 0, equ = 0, sec = 0;
        first(0, 0, 0, n, map, &fir, &equ, &sec);
        printf("%d %d %d\n", fir, sec, equ);
    }
    return 0;
}
