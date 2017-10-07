#include<stdio.h>

int main(){
    char sound[100010];
    scanf("%s", sound);
    char rule[26];
    for (int i = 0;i < 26;++i) rule[i] = i;
    int n;
    scanf("%d", &n);
    while (n--){
        char tmp1, tmp2;
        getchar();
        tmp1 = getchar();
        getchar();
        tmp2 = getchar();
        for (int i = 0;i < 26;++i){
            if (rule[i] == tmp2 - 'A') rule[i] = tmp1 - 'A';
        }
    }
    for (int i = 0;i < 100010;++i){
        if (sound[i] == '\0') break;
        putchar(rule[sound[i] - 'A'] + 'A');
    }
    return 0;
}
            
