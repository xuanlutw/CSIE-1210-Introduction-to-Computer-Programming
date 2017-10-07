#include<stdio.h>
#include<stdlib.h>

typedef struct coord{
    int x;
    int y;
}Coord;

int compare(const void* a, const void* b){
    Coord pta = *(Coord*) a;
    Coord ptb = *(Coord*) b;
    if ((pta.x * pta.x + pta.y * pta.y) != (ptb.x * ptb.x + ptb.y * ptb.y)) return (pta.x * pta.x + pta.y * pta.y) - (ptb.x * ptb.x + ptb.y * ptb.y);
    if (pta.x != ptb.x) return pta.x - ptb.x;
    if (pta.y != ptb.y) return pta.y - ptb.y;
    else return 0;
}
    
int main(){
    Coord pt[100001];
    int n;
    for (n = 0;scanf("%d%d", &pt[n].x, &pt[n].y) != EOF;++n);
    qsort(pt, n, sizeof(Coord), compare);
    long long int ans = 0;
    ans = pt[0].x * pt[0].x + pt[0].y * pt[0].y;
    for (int i = 0;i < n - 1;++i) ans += (pt[i + 1].x - pt[i].x) * (pt[i + 1].x - pt[i].x) + (pt[i + 1].y - pt[i].y) * (pt[i + 1].y - pt[i].y);
    printf("%lld", ans);
}
