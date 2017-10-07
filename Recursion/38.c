#include<stdio.h>

int rec(int goal, int na, int nb, int nc, int ma, int mb, int mc){
    if (goal == 0){
        printf("yes\n");
        return 1;
    }
    int fl = 0;
    if (na && goal >= ma){
        if (rec(goal - ma, na - 1, nb, nc, ma, mb, mc)) fl = 1;
    }
    if (nb && goal >= mb && !fl){
        if (rec(goal - mb, na, nb - 1, nc, ma, mb, mc)) fl = 1;
    }
    if (nc && goal >= mc && !fl){
        if (rec(goal - mc, na, nb, nc - 1, ma, mb, mc)) fl = 1;
    }
    if (fl) return 1;
    else return 0;
}

int main(){
    int n, goal, na, nb, nc, ma, mb, mc;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d%d%d%d%d", &goal, &na, &nb, &nc, &ma, &mb, &mc);
        int k = rec(goal, na, nb, nc, ma, mb, mc);
        if (!k) printf("no\n");
    }
    return 0;
}
