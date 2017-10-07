#include<stdio.h>
#include<stdlib.h>

int num_bit(long long a){
    int ans = 0;
    for (int i = 0;i < 64;++i){
        ans += a & 1;
        a >>= 1;
    }
    return ans;
}

int compare(const void* ca, const void* cb){
    long long a = *(long long*)ca;
    long long b = *(long long*)cb;
    if (num_bit(a) > num_bit(b)) return 1;
    else if (num_bit(a) < num_bit(b)) return -1;
    else if (a > b) return 1;
    else if (b > a) return -1;
    else return 0;
}

int main(){
    int n;
    long long num[1024];
    for (n = 0;scanf("%lld", &num[n]) != EOF;++n);
    qsort(num, n, sizeof(long long), compare);
    for (int i = 0;i < n;++i) printf("%lld\n", num[i]);
    return 0;
}
