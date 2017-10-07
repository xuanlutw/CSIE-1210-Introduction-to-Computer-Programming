#include<stdio.h>

int main(){
    int n, m, locmax, locmax2, locmaxi, locmax2i, globalmax = 0, globali, globalr;
    scanf("%d%d", &n, &m);
    for (int i = 0;i < n;++i){
        locmax = 0;
        locmax2 = 0;
        for (int j = 0;j < m;++j){
            int tmp;
            scanf("%d", &tmp);
            if (tmp >= locmax){
                locmax2 = locmax;
                locmax2i = locmaxi;
                locmax = tmp;
                locmaxi = j + 1;
            }
            else if(tmp >= locmax2){
                locmax2 = tmp;
                locmax2i = j + 1;
            }
            if (tmp >= globalmax){
                globalmax = tmp;
                globali = j + 1;
                globalr = i + 1;
            }
        }
        printf("%d %d\n", locmaxi, locmax2i);
    }
    printf("%d %d", globalr, globali);
    return 0;
} 
