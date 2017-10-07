#include<stdio.h>

int sign_cp(int a1, int a2, int b1, int b2){
    int a = a1 * b2 - a2 * b1;
    if (a > 0) return 1;
    else if (a < 0) return -1;
    else return 0;
}

int pt_is_inside(int a, int b, int x1, int y1, int x2, int y2, int x3, int y3){
    int cp1 = sign_cp(x1 - a, y1 - b, x2 - a, y2 - b);
    int cp2 = sign_cp(x2 - a, y2 - b, x3 - a, y3 - b);
    int cp3 = sign_cp(x3 - a, y3 - b, x1 - a, y1 - b);
    if ((cp1 * cp2) >= 0 && (cp2 * cp3) >=0 && (cp3 * cp1) >= 0) return 1;
    else return 0;
}

int block_is_inside(int a, int b, int x1, int y1, int x2, int y2, int x3, int y3){
    int fl = 0;
    if (pt_is_inside(a, b, x1, y1, x2, y2, x3, y3) == 0) fl = 1;
    if (pt_is_inside(a + 1, b, x1, y1, x2, y2, x3, y3) == 0) fl = 1;
    if (pt_is_inside(a, b + 1, x1, y1, x2, y2, x3, y3) == 0) fl = 1;
    if (pt_is_inside(a + 1, b + 1, x1, y1, x2, y2, x3, y3) == 0) fl = 1;
    if (fl == 0) return 1;
    else return 0;
}

int main(){
    int x1, y1, x2, y2, x3, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    int ans = 0;
    for (int i = -1000;i < 1002;++i){
        for (int j = -1000;j < 1002;++j){
            if (block_is_inside(i, j, x1, y1, x2, y2, x3, y3) == 1){ 
                ++ans;
               // printf("%d %d\n", i, j);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
