#include<stdio.h>

int sum_eq (int x, int y, int k, int map[11][11], int pat[11][11], int d){
    int sum1 = 0, sum2 = 0;
    for (int i = 0;i < k;++i){
        for (int j = 0;j < k;++j) sum1 += map[i + x][j + y]; 
    }
    for (int i = 0;i < k;++i){
        for (int j = 0;j < k;++j) sum2 += pat[i][j]; 
    }
    int del = sum1 - sum2;
    del > 0? del: -del;
    if (d >= del) return 1;
    else return 0;
}

int mismatch (int x, int y, int k, int map[11][11], int pat[11][11], int m){
    int mis = 0;
    for (int i = 0;i < k;++i){
        for (int j = 0;j < k;++j){
            if (map[i + x][j + y] != pat[i][j]) ++mis;
        } 
    }
    if (m >= mis) return 1;
    else return 0;
}

int main(){
    int n, k, m, d, map[11][11], pat[11][11];
    scanf("%d%d%d%d", &n, &k, &m, &d);
    for (int i = 0;i < n;++i){
        for (int j = 0;j < n;++j) scanf("%d", &map[i][j]);
    }
    for (int i = 0;i < k;++i){
        for (int j = 0;j < k;++j) scanf("%d", &pat[i][j]);
    }
    int ansx = -1, ansy = -1;
    for (int i = 0;i <= n - k;++i){
        for (int j = 0;j <= n - k;++j){
            if (sum_eq (i, j, k, map, pat, d) && mismatch (i, j, k, map, pat, m)){
                ansx = i;
                ansy = j;
            }
        }
    }
    printf("%d %d", ansx, ansy);
} 
