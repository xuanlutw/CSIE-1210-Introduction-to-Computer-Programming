#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double do_exp(char* tmp){
    int i, j;
    double p, expr1, expr2;
    if (tmp[0] != '(') return atof(tmp);
    for (i = 1;;++i){
        if (tmp[i] == ' ') break;
    }
    tmp[i] = '\0';
    p = atof(tmp + 1);
    if (tmp[i + 1] == '('){
        int fl = 0;
        for(j = i + 1;;++j){
            if (tmp[j] == '(') ++fl;
            else if (tmp[j] == ')') --fl;
            if (!fl) break;
        }
        ++j;
        tmp[j] = '\0';
        expr1 = do_exp(tmp + i + 1);
    }
    else{ 
        for (j = i + 1;;++j){
            if (tmp[j] == ' ') break;
        }
        tmp[j] = '\0';
        expr1 = atof(tmp + i + 1);
    }
    if (tmp[j + 1] == '('){
        int fl = 0;
        for(i = j + 1;;++i){
            if (tmp[i] == '(') ++fl;
            else if (tmp[i] == ')') --fl;
            if (!fl) break;
        }
        ++i;
        tmp[i] = '\0';
        expr2 = do_exp(tmp + j + 1);
    }
    else{ 
        for (i = j + 1;;++i){
            if (tmp[i] == ')') break;
        }
        tmp[i] = '\0';
        expr2 = atof(tmp + j + 1);
    }
    return p * (expr1 + expr2) + (1.0 - p) * (expr1 - expr2);
}

int main(){
    char tmp[1000];
    while (fgets(tmp, 1000, stdin) != NULL){
        double ans = do_exp(tmp);
        printf("%.2lf\n", ans);
    }
    return 0;
}
