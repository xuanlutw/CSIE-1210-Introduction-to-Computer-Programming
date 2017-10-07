#include<stdio.h>

int main(){
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &c, &e, &b, &d, &f);
    printf("%d\n%d %d %d", a * b + c * d + e * f, c * f - d * e, e * b - a * f, a * d - b * c);
    return 0;
} 

