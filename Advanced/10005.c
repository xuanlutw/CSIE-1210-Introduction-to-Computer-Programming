#include<stdio.h>

int main(){
    int n = 0, fl1 = 1, fl2 = 0;
    char tmp;
    while(scanf("%c", &tmp) != EOF){
        if(tmp == '\n'){
            if (!fl1 && fl2) printf("%d\n", n);
            fl1 = 1;
            fl2 = 0;
            n = 0;
        }
        else if (tmp >= '0' && tmp <= '9'){
            n = n * 10 + tmp - '0';
            fl1 = 0;
            fl2 = 1;
        }
        else{
            if (!fl1 && fl2) printf("%d\n", n);
            fl1 = 0;
            fl2 = 0;
            n = 0;
        }
    }
    if (!fl1 && fl2) printf("%d\n", n);
    return 0;
}
        
