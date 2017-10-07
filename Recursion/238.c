#include<stdio.h>

int rec(int now, int value, int n, int num[16]){
    if (value == 0) return 1;
    else if (now == n) return 0;
    int a = rec(now + 1, value, n, num);
    if (value >= num[now]) a += rec(now + 1, value - num[now], n, num);
    return a;
}

int main(){
    int n, num[16];
    scanf("%d", &n);
    for (int i = 0;i < n;++i) scanf("%d", &num[i]);
    int tmp;
    while(scanf("%d", &tmp) != EOF){
        printf("%d\n", rec(0, tmp, n, num));
    }
    return 0;
}
