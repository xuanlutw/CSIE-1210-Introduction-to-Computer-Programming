#include<stdio.h>

int local_sum(int i, int j, int sol[9]){
    int ans = ((sol[i] & (1 << j)) > 0);
    if (i != 0) ans += ((sol[i - 1] & (1 << j)) > 0);
    if (i != 8) ans += ((sol[i + 1] & (1 << j)) > 0);
    if (j != 0) ans += ((sol[i] & (1 << (j - 1))) > 0);
    if (j != 8) ans += ((sol[i] & (1 << (j + 1))) > 0);
    if (i != 0 && j != 0) ans += ((sol[i - 1] & (1 << (j - 1))) > 0);
    if (i != 0 && j != 8) ans += ((sol[i - 1] & (1 << (j + 1))) > 0);
    if (i != 8 && j != 0) ans += ((sol[i + 1] & (1 << (j - 1))) > 0);
    if (i != 8 && j != 8) ans += ((sol[i + 1] & (1 << (j + 1))) > 0);
    return ans;
}
    
int check(int now, int sol[9], int map[9][9], int ff){
    int fl = 1;
    for (int i = 0;i < now - 1;++i){
        for (int j = 0;j < 9;++j){
            if (local_sum(i, j, sol) != map[i][j]) fl = 0;
            //printf("%d\n", local_sum(i, j, sol)); 
        }
    }
    if (now == 9){
        for (int j = 0;j < 9;++j){
            if (local_sum(8, j, sol) != map[8][j]) fl = 0;
        }
    }
    if (now == 9 && fl && ff){
        for (int i = 0;i < 9;++i){
            printf("%d", sol[i] & 1);
            for (int j = 1;j < 9;++j) printf(" %d", ((sol[i] & (1 << j)) > 0));
            printf("\n");
        }
    }
    return fl;
}

int DFS(int now, int sol[9], int map[9][9]){
    if (now == 9) return check(now, sol, map, 1);
    for (int i = 0;i < (1 << 9);++i){
        sol[now] = i;
        if (!check(now + 1, sol, map, 0)) continue;
        //printf("%d\n", now);
        int k = DFS(now + 1, sol, map);
        if (k) return 1;
    }
    return 0;
}

int main(){
    int sol[9] = {0};
    int map[9][9] = {0};
    for (int i = 0;i < 9;++i){
        for (int j = 0;j < 9;++j) scanf("%d", &map[i][j]);
    }
    if (!DFS(0, sol, map)) printf("no solution\n");
    return 0;
}
