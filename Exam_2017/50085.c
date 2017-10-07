#include<stdio.h>
 
int count(int tx, int ty, int l, int w,int map[600][600]){
    int ans = 0, i, j;
    for (i = tx;i < tx + l;++i){
        for (j = ty;j < ty + w;++j){
            if (map[i][j] == 2) ++ans;
        }
    }
    return ans;
}
 
int countx(int x, int y1, int y2, int map[600][600]){
    int ans = 0, i, j;
    for (i = y1;i < y2;++i){
        if (map[x][i] == 2) ++ans;
    }
    return ans;
}
 
int county(int y, int x1, int x2, int map[600][600]){
    int ans = 0, i, j;
    for (i = x1;i < x2;++i){
        if (map[i][y] == 2) ++ans;
    }
    return ans;
}
 
int delet_tank(int tx, int ty, int w, int l, int map[600][600]){
    int i, j;
    for (i = tx;i < tx + l;++i){
        for (j = ty;j < ty + w;++j) map[i][j] = 0;
    }
}
 
int delet_tankx(int x, int y1, int y2, int map[600][600]){
    int i, j;
    for (i = y1;i < y2;++i) map[x][i] = 0;
}
 
int delet_tanky(int y, int x1, int x2, int map[600][600]){
    int i, j;
    for (i = x1;i < x2;++i) map[i][y] =0;
}
 
int write_tank(int tx, int ty, int w, int l, int map[600][600]){
    int i, j;
    for (i = tx;i < tx + l;++i){
        for (j = ty;j < ty + w;++j) map[i][j] = 1;
    }
}
int write_tankx(int x, int y1, int y2, int map[600][600]){
    int i, j;
    for (i = y1;i < y2;++i) map[x][i] = 1;
}
 
int write_tanky(int y, int x1, int x2, int map[600][600]){
    int i, j;
    for (i = x1;i < x2;++i) map[i][y] =1;
}
 
 
int main(){
    int n, m, l, w, tx = 0, ty = 0, i, j;
    scanf("%d%d%d%d", &n, &m, &l, &w);
    int o;
    int map[600][600] = {0};
    scanf("%d", &o);
    for (i = 0;i < o;++i){
        int tmpx, tmpy;
        scanf("%d %d", &tmpy, &tmpx);
        map[tmpx][tmpy] = 2;
      }
 
    for (i = 0;i < l;++i){
        for (j = 0;j < w;++j) map[i][j] = 1;
    }
 
    int com;
    while(scanf("%d", &com) != EOF){
        if (com == 1 && ty < m - w && county(ty + w, tx, tx + l, map)<=1){
            delet_tanky(ty, tx, tx + l, map);
            ty += 1;
            write_tanky(ty + w - 1, tx, tx + l, map);
        }
        if (com == 2 && tx < n - l && countx(tx + l, ty, ty + w, map)<=1){
            delet_tankx(tx, ty, ty + w, map);
            tx += 1;
            write_tankx(tx + l - 1, ty, ty + w, map);
        }
        if (com == 3 && ty > 0 && county(ty - 1, tx, tx + l, map)<=1){
            delet_tanky(ty + w - 1, tx, tx + l, map);
            ty -= 1;
            write_tanky(ty, tx, tx + l, map);
        }
        if (com == 4 && tx > 0 && countx(tx - 1, ty, ty + w, map)<=1){
            delet_tankx(tx + l - 1, ty, ty + w, map);
            tx -= 1;
            write_tankx(tx, ty, ty + w, map);
        }
        if (com == 5 && ty < m - w && tx < n - l && count(tx + 1, ty + 1, l, w, map)<=1){
            delet_tank(tx, ty, w, l, map);
            ty += 1;
            tx += 1;
            write_tank(tx, ty, w, l, map);
        }
        if (com == 0){
            for (i = 0;i < n;++i){
                for (j = 0;j < m;++j) printf("%d", map[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
