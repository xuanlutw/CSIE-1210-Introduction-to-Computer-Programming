#include<stdio.h>

int area(int lux, int luy, int rdx, int rdy){
    if (lux > rdx || luy > rdy) return 0;
    return (lux - rdx) * (luy - rdy);
}

int max(int x, int y, int z){
    int mm = x;
    if (y > mm) mm = y;
    if (z > mm) mm = z;
    return mm;
}

int min(int x, int y, int z){
    int mm = x;
    if (y < mm) mm = y;
    if (z < mm) mm = z;
    return mm;
} 

int main(){
    int a[4], b[4], c[4];
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    scanf("%d%d%d%d", &b[0], &b[1], &b[2], &b[3]);
    scanf("%d%d%d%d", &c[0], &c[1], &c[2], &c[3]);
    int ans = 0;
    ans += area(a[0], a[1], a[2], a[3]);
    ans += area(b[0], b[1], b[2], b[3]);
    ans += area(c[0], c[1], c[2], c[3]);
    int lux, luy, rdx, rdy;
    lux = a[0] > b[0]?a[0]:b[0];
    luy = a[1] > b[1]?a[1]:b[1];
    rdx = a[2] < b[2]?a[2]:b[2];
    rdy = a[3] < b[3]?a[3]:b[3];
    ans -= area(lux, luy, rdx, rdy);
    lux = a[0] > c[0]?a[0]:c[0];
    luy = a[1] > c[1]?a[1]:c[1];
    rdx = a[2] < c[2]?a[2]:c[2];
    rdy = a[3] < c[3]?a[3]:c[3];
    ans -= area(lux, luy, rdx, rdy);
    lux = c[0] > b[0]?c[0]:b[0];
    luy = c[1] > b[1]?c[1]:b[1];
    rdx = c[2] < b[2]?c[2]:b[2];
    rdy = c[3] < b[3]?c[3]:b[3];
    ans -= area(lux, luy, rdx, rdy);
    lux = max(a[0], b[0], c[0]);
    luy = max(a[1], b[1], c[1]);
    rdx = min(a[2], b[2], c[2]);
    rdy = min(a[3], b[3], c[3]);
    ans += area(lux, luy, rdx, rdy);
    printf("%d", ans);
} 
