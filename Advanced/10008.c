#include<stdio.h>

int main(){
    int tmp;
    while (scanf("%d", &tmp) != EOF){
        printf("%d %d %d %d %d %d %d\n", tmp / 1000, (tmp % 1000) / 500, (tmp % 500) / 100, (tmp % 100) / 50, (tmp % 50) / 10, (tmp % 10) / 5, (tmp % 5));
    }
    return 0;
}
