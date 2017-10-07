#include<stdio.h>

int main(){
    long long a, b, n;
    while(scanf("%lld %lld %lld", &a, &b, &n) != EOF){
        a %= n;
        b %= n;
        long long res = b;
        long long ans = 0;
        for (int i = 0;i < 63;++i){
            if (a & ((long long)1 << i)) ans = (ans + res) % n;
            res = (res * 2) % n;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
