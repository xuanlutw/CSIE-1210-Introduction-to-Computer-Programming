#include<stdio.h>

void DFS(int level, int n, int m, int rule[2][100], int* order, int* done){
    if (level == n){
        for (int i = 0;i < n;++i) printf("%c", *(order + i) + 'A');
        printf("\n");
    }
    for (int i = 0;i < n;++i){
        if (*(done + i)) continue;
        int fl = 0;
        for (int j = 0;j < m;++j){
            if (rule[0][j] != i) continue;
            if (rule[1][j] == level) fl = 1;
        }
        if (fl) continue;
        *(done + i) = 1;
        *(order + level) = i;
        DFS(level + 1, n, m, rule, order, done);
        *(done + i) = 0;
    }
    return;
}

int main(){
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF){
        int rule[2][100];
        int order[10] = {0};
        int done[10] = {0};
        for (int i = 0;i < m;++i) scanf("%d%d",  &rule[0][i], &rule[1][i]);
        for (int i = 0;i < m;++i){
            --rule[0][i];
            --rule[1][i];
        }
        DFS(0, n, m, rule, order, done);
    }
    return 0;
}
