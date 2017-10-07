#include<stdio.h>
#include<string.h>

int match(char* mon, char* child){
    for (int i = 0;i < strlen(mon);++i){
        char tmp[51];
        strcpy(tmp, mon + i);
        tmp[strlen(child)] = '\0';
        if (!strcmp(tmp, child)) return 1;
    }
    return 0;
}
 
int main(){
    int n;
    scanf("%d", &n);
    char dic[n][51];
    for (int i = 0;i < n;++i) scanf("%s", dic[i]);
    int q;
    scanf("%d", &q);
    char tmp[51];
    for (int i = 0;i < q;++i){
        scanf("%s", tmp);
        int ans = 0;
        for (int j = 0;j < n;++j){
            if (match(dic[j], tmp)) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
