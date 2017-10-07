#include<stdio.h>
#include<math.h>

int main(){
    double a, b, c;
    while(scanf("%lf%lf%lf", &a, &b, &c) != EOF) printf("%.20lf %.20lf\n", (-b - sqrt(b * b - 4 * a * c)) / (2 * a), (-b + sqrt(b * b - 4 * a * c)) / (2 * a));
    return 0;
}

