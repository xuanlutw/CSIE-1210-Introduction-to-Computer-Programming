#include<stdio.h>

int main(){
    int m;
    scanf("%d", &m);
    if (m <= 0) printf("0");
    else if (m & 1) printf("0");
    else if (m <= 10000 && m >= 1000) printf("0");
    else printf("1");
    return 0;
}
