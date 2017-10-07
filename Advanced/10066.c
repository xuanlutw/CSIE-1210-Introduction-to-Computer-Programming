#include<stdio.h>
#include <stdlib.h>

double frandom() {
    return rand() * 1.f / RAND_MAX;
}

int main(){
    srand(87878787);
    int n, r, cas = 0;
    while (scanf("%d%d", &r, &n) != EOF){
        ++cas;
        int data[4][8] = {0};
        for (int i = 0;i < n;++i) scanf("%d%d%d", &data[0][i], &data[1][i], &data[2][i]);
        for (int i = 0;i < 5000000;++i){
            double min = 999999;
            int num;
            double sx = frandom() * r * (frandom()>0.5?1:-1);
            double sy = frandom() * r * (frandom()>0.5?1:-1);
            double sz = frandom() * r * (frandom()>0.5?1:-1);
            if (sx * sx + sy * sy + sz * sz > r * r) continue;
            for (int i = 0;i < n;++i){
                double tmp =  (sx - data[0][i]) * (sx - data[0][i]) +  (sy - data[1][i]) * (sy - data[1][i]) + (sz - data[2][i]) * (sz - data[2][i]);
                if (tmp < min){
                    min = tmp;
                    num = i;
                }
            }
            ++data[3][num];
        }
        printf("Case #%d:\n", cas);
        int sum = 0;
        for (int i = 0;i < n;++i) sum += data[3][i];
        for (int i = 0;i < n;++i) printf("%.0lf\n", (double)data[3][i] / (sum / 100));
    }
        return 0;
}

