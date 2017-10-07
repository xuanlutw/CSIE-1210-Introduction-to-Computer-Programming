#include<stdio.h>

int main(){
    int n = 0;
    int tmp;
    double ansH = 0;
    double ansA = 0;
    while (scanf("%d", &tmp) != EOF){
#ifdef HUNDRED
        printf("%d ", tmp);
        ansH += tmp;
#endif
#ifdef APLUS
        if (tmp >= 90){
            printf("A+ ");
            ansH += 95;
            ansA += 4.3;
        }
        else if (tmp >= 85){
            printf("A ");
            ansH += 87;
            ansA += 4.0;
        }
        else if (tmp >= 80){
            printf("A- ");
            ansH += 82;
            ansA += 3.7;
        }
        else if (tmp >= 77){
            printf("B+ ");
            ansH += 78;
            ansA += 3.3;
        }
        else if (tmp >= 73){
            printf("B ");
            ansH += 75;
            ansA += 3.0;
        }
        else if (tmp >= 70){
            printf("B- ");
            ansH += 70;
            ansA += 2.7;
        }
        else if (tmp >= 67){
            printf("C+ ");
            ansH += 68;
            ansA += 2.3;
        }
        else if (tmp >= 63){
            printf("C ");
            ansH += 65;
            ansA += 2.0;
        }
        else if (tmp >= 60){
            printf("C- ");
            ansH += 60;
            ansA += 1.7;
        }
        else{
            printf("F ");
            ansH += 50;
            ansA += 0;
        }
#endif
    ++n;
    }
#ifdef HUNDRED
    printf("%.1lf", ansH / n);
#endif
#ifdef APLUS
    printf("%.1lf %.1lf", ansA / n, ansH / n);
#endif
    return 0;
}
