#include<stdio.h>

int main(){
    int n;
    while (scanf("%d", &n) == 1){
        int seesaw[3][32] = {0};
        int weight = 0;
        for (int i = 0;i < n;++i){
            scanf("%d", &seesaw[0][i]);
            if (i) seesaw[1][i] = seesaw[1][i - 1] + weight;
            weight += seesaw[0][i];
        }
        weight = seesaw[0][n - 1];
        for (int i = n - 2;i >= 0;++i){
            seesaw[2][i] = seesaw[1][i + 1] + weight;
            weight += seesaw[0][i];
        }
        int bal = 0;
        for (bal = 0;seesaw[1][bal] < seesaw[2][bal];++bal);
        if (seesaw[1][bal] != seesaw[2][bal]) printf("N\n");
        else{
            for (int i = 0;i < n;++i){
                if (i) printf(" ");
                if (i == bal) printf(" _^_");
                else printf("%d", seesaw[0][i]);
            }
        }
    }
    return 0;
}
