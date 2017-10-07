#include<stdio.h>

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF){
        int t = gcd(a, b);
        printf("%d / %d\n", a / t, b / t);
    }
    return 0;
}
