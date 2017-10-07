#include<stdio.h>

int main(){
    int ans = 0;
    int tmp;
    while(scanf("%d", &tmp) != EOF) ans += tmp;
    printf("%d", ans);
    return 0;
}
