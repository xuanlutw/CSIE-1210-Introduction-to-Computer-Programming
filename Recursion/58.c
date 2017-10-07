#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
    return *(int *) a < *(int *) b;
}

int size_of_lake(int x, int y, int n, int m,int map[512][512]){
    if (map[x][y] == 0) return 0;
    int ans = 1;
    map[x][y] = 0;
    if (x != n - 1) ans += size_of_lake(x + 1, y, n, m, map);
    if (x) ans += size_of_lake(x - 1, y, n, m, map);
    if (y != m - 1) ans += size_of_lake(x, y + 1, n, m, map);
    if (y) ans += size_of_lake(x, y - 1, n, m, map);
    return ans;
}

int main(){
    int n, m ,map[512][512] = {0};
    scanf("%d%d", &n, &m);
    for (int i = 0;i < n;++i){
        for (int j = 0;j < m;++j) scanf("%d", &map[i][j]);
    }
    int ans[80010] = {0}, num = 0;
    for (int i = 0;i < n;++i){
        for (int j = 0;j < m;++j){
            int tmp = size_of_lake(i, j, n, m, map);
            if (tmp){
                ans[num] = tmp;
                ++num;
            }
        }
    }
    qsort(ans, num, sizeof(int), compare);
    for (int i = 0;i < num;++i) printf("%d\n", ans[i]);
    return 0;
}
