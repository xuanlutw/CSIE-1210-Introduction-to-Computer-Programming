#include<stdio.h>

void catch(int lx, int ly, int rx, int ry, int map[1024][1024]){
    int ans = 0;
    for (int i = lx;i <= rx;++i){
        for (int j = ly;j <= ry;++j){
            if (!map[i][j]) ++ans;
        }
    }
    printf("%d", ans);
    for (int i = lx;i <= rx;++i){
        for (int j = ly;j <= ry;++j){
            if (!map[i][j]){
                printf(" (%d, %d)", i, j);
                map[i][j] = 1;
            }
        }
    }
    printf("\n");
    return;
}

int main(){
    int map[1024][1024] = {0};
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0;i < q;++i){
        int lx, ly, rx, ry;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        catch(lx, ly, rx, ry, map);
    }
    return 0;
}
