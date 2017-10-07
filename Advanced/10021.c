#include<stdio.h>

int main(){
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF){
        int map[m][n];
        for (int i = 0;i < m;++i){
            for (int j = 0;j < n;++j){
                int tmp;
                scanf("%d", &tmp);
                if (tmp) map[i][j] = -1;
                else map[i][j] = 0;
            }
        }
        map[0][0] = 1;
        for (int i = 0;i < m;++i){
            for (int j = 0;j < n;++j){
                if (map[i][j] == -1) continue;
                if (i > 0 && map[i - 1][j] != -1) map[i][j] += map[i - 1][j];
                if (j > 0 && map[i][j - 1] != -1) map[i][j] += map[i][j - 1];
                map[i][j] %= 10000;
            }
        }
        printf("%d\n", map[m - 1][n - 1]);
    }
    return 0;
}

