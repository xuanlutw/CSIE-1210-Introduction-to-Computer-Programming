#include<stdio.h>

int main(){
    int n, zeros = 0;
    scanf("%d", &n);
    for (int i = 0;i < n;++i){
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 0) ++zeros;
        else{
            printf("%d", tmp);
            if (!(zeros == 0 && i == n - 1)) printf(" ");
        }
    }
    for (int i = 0;i < zeros;++i){
        printf("0");
        if (i != zeros - 1) printf(" ");
    }
    return 0;
}
