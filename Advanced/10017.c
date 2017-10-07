#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n); 
    int tmp[2][100000];
    scanf("%d %d", &tmp[0][0], &tmp[1][0]);
    for (int i = 1;i < 2 * n;++i){
        int tmpx, tmpy, min = 100000000;
        scanf("%d %d", &tmpx, &tmpy);
        tmp[0][i] = tmpx;
        tmp[1][i] = tmpy;
        for (int j = (i + 1) % 2;j < i;j += 2){
            if (abs(tmpx - tmp[0][j]) + abs(tmpy - tmp[1][j]) < min) min = abs(tmpx - tmp[0][j]) + abs(tmpy - tmp[1][j]);
        }
        printf("%d\n", min);
    }
    return 0;
}
