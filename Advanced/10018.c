#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    char ans[100010] = {0};
    for (int i = 0;i < n;++i){
        int tmp;
        scanf("%d", &tmp);
        ++ans[tmp];
    }
    for (int i = 0;i < 100005;++i){
        if (ans[i] >= 2){
            printf("%d", i);
            break;
        }
    }
    return 0;
}
     
