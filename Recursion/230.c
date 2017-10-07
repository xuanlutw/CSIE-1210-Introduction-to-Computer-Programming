#include<stdio.h>

int DFS(int n, int now, int value, int weight, int w[32], int v[32]){
    if (n == now) return value;
    int fl = 0;
    if (w[now] <= weight) fl = DFS(n, now + 1, value + v[now], weight - w[now], w, v);
    int a = DFS(n, now + 1, value, weight, w, v);
    if (a > fl) return a;
    return fl;
}

int main(){
    int n, w[32] = {0}, v[32] = {0}, weight;
    scanf("%d%d", &n, &weight);
    for (int i = 0;i < n;++i) scanf("%d%d", &w[i], &v[i]);
    printf("%d", DFS(n, 0,  0, weight, w, v));
    return 0;
}
