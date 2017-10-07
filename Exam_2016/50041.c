#include<stdio.h>

int main(){
    int n, x1, x2, x3;
    scanf("%d%d%d", &n, &x2, &x1);
    int cost = 0;
    if (x1 > x2) cost += 3 * (x1 - x2);
    else cost += 2 * (x2 - x1);
    x3 = x2;
    x2 = x1;
    for (int i = 2;i < n;++i){
        scanf("%d", &x1);
        if (x1 > x2 && x2 > x3) cost += 4 * (x1 - x2);
        else if (x1 > x2) cost += 3 * (x1 - x2);
        else if (x2 > x1 && x2 > x3) cost += 3 * (x2 - x1);
        else cost += 2 * (x2 - x1);
        x3 = x2;
        x2 = x1;
    }
    printf("%d", cost);
    return 0;
}
