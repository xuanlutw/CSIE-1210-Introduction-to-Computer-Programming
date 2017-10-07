#include<stdio.h>
#include <stdlib.h>

double frandom() {
    return rand() * 1.f / RAND_MAX;
}

int main(){
    srand(878787);
    int n, a, b, cas = 0;
    while (scanf("%d%d%d", &n, &a, &b) != EOF){
        ++cas;
        int data[3][8] = {0};
        for (int i = 0;i < n;++i) scanf("%d%d", &data[0][i], &data[1][i]);
        for (int i = 0;i < 10000000;++i){
            double min = 999999;
            int num;
            double sx = frandom() * a;
            double sy = frandom() * b;
            for (int i = 0;i < n;++i){
                double tmp =  (sx - data[0][i]) * (sx - data[0][i]) + (sy - data[1][i]) * (sy - data[1][i]);
                if (tmp < min){
                    min = tmp;
                    num = i;
                }
            }
            ++data[2][num];
        }
        printf("Case #%d:\n", cas);
        int sum = 0;
        for (int i = 0;i < n;++i) sum += data[2][i];
        for (int i = 0;i < n;++i) printf("%.0lf\n", (double)data[2][i] / (sum / 100));
    }
        return 0;
}

