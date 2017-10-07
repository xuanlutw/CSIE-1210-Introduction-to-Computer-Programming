#include<stdio.h>

int check_partial(int now, int p, int color[32], int bet[2][256]){
    int fl = 1;
    for (int i = 0;i < p;++i){
        if (bet[0][i] >= now || bet[1][i] >= now) continue;
        if (color[bet[0][i]] == color[bet[1][i]]) fl = 0;
    }
    if (fl == 1) return 1;
    return 0;
}

int check(int n, int p, int color[32], int bet[2][256]){
    int fl = 1;
    for (int i = 0;i < p;++i){
        if (color[bet[0][i]] == color[bet[1][i]]) fl = 0;
    }
    if (fl == 1){
        for (int i = 0;i < n;++i) printf("%d\n", color[i]);
        return 1;
    }
    return 0;
}
    
int DFS(int n, int p, int c, int now, int color[32], int bet[2][256]){
    if (now == n) return check(n, p, color, bet);
    for (int i = 1;i <= c;++i){
        color[now] = i;
        if (!check_partial(now + 1, p, color, bet)) continue;
        int k = DFS(n, p, c, now + 1, color, bet);
        if (k) return 1;
    }
    return 0;
}

int main(){
    int n, p, c;
    scanf("%d%d%d", &n, &c, &p);
    int bet[2][256] = {0};
    for (int i = 0;i < p;++i) scanf("%d%d", &bet[0][i], &bet[1][i]);
    int color[32] = {0}; 
    if (!DFS(n, p, c, 0, color, bet)) printf("no solution.\n");
    return 0;
}
