#include<stdio.h>

int main(){
    int n, m, sx, sy, ex, ey, q, length;
    scanf("%d%d%d%d%d%d%d", &n, &m, &sx, &sy, &ex, &ey, &q);
    int cap[2][1024] = {0};
    char map[1024][1024] = {0};
    if (sx == ex && sy > ey){
        for (int i = sy - ey;i >= 0;--i){
            map[sx][ey + i] = 1;
            cap[0][sy - ey - i] = sx;
            cap[1][sy - ey - i] = ey + i;
        }
        length = sy - ey + 1;
    }
    else if (sx == ex){    
        for (int i = 0;i <= ey - sy;++i){
            map[sx][sy + i] = 1;
            cap[0][i] = sx;
            cap[1][i] = sy + i;
        }
        length = ey - sy + 1;
    }
    else if (sy == ey && sx > ex){
        for (int i = sx - ex;i >= 0;--i){
            map[ex + i][sy] = 1;
            cap[0][sx - ex - i] = ex + i;
            cap[1][sx - ex - i] = sy;
        }
        length = sx - ex + 1;
    }
    else if (sy == ey){    
        for (int i = 0;i <= ex - sx;++i){
            map[sx + i][sy] = 1;
            cap[0][i] = sx + i;
            cap[1][i] = sy;
        }
        length = ex - sx + 1;
    }
         //for (int i = 0;i < length;++i) printf ("(%d, %d)", cap[0][i], cap[1][i]);
         //printf("\n");
    for (;q > 0;--q){
        int tmp, fl = 1;
        scanf("%d", &tmp);
        map[cap[0][length - 1]][cap[1][length - 1]] = 0;
        if (tmp == 0 && map[cap[0][0] + 1][cap[1][0]] != 1 && cap[0][0] != n - 1){
            map[cap[0][0] + 1][cap[1][0]] = 1;
            for (int i = length - 2;i >= 0;--i){
                cap[0][i + 1] = cap[0][i];
                cap[1][i + 1] = cap[1][i];
            }
            cap[0][0] = cap[0][0] + 1;
            fl = 0;
        }
        if (tmp == 1 && map[cap[0][0] - 1][cap[1][0]] != 1 && cap[0][0] != 0){
            map[cap[0][0] - 1][cap[1][0]] = 1;
            for (int i = length - 2;i >= 0;--i){
                cap[0][i + 1] = cap[0][i];
                cap[1][i + 1] = cap[1][i];
            }
            cap[0][0] = cap[0][0] - 1;
            fl = 0;
        }
        if (tmp == 2 && map[cap[0][0]][cap[1][0] + 1] != 1 && cap[1][0] != m - 1){
            map[cap[0][0]][cap[1][0] + 1] = 1;
            for (int i = length - 2;i >= 0;--i){
                cap[0][i + 1] = cap[0][i];
                cap[1][i + 1] = cap[1][i];
            }
            cap[1][0] = cap[1][0] + 1;
            fl = 0;
         }
         if (tmp == 3 && map[cap[0][0]][cap[1][0] - 1] != 1 && cap[1][0] != 0){
            map[cap[0][0]][cap[1][0] - 1] = 1;
            for (int i = length - 2;i >= 0;--i){
                cap[0][i + 1] = cap[0][i];
                cap[1][i + 1] = cap[1][i];
            }
            cap[1][0] = cap[1][0] - 1;
            fl = 0;
         }
         if (fl) map[cap[0][length - 1]][cap[1][length - 1]] = 1;
         //for (int i = 0;i < length;++i) printf ("(%d, %d)", cap[0][i], cap[1][i]);
         //printf("\n");
    }
    for (int i = 0;i < n;++i){
        for (int j = 0;j < m;++j) printf("%d", map[i][j]);
        printf("\n");
    }
    return 0;
}
