#include<stdio.h>

int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        int tmp, pre;
        int ans = 1;
        scanf("%d", &pre);
        for (int i = 1;i < n;++i){
            scanf("%d", &tmp);
            if (tmp != pre){
                pre = tmp;
                ++ans;
            }
        }
        printf("%d", ans);
    }
    return 0;
}
