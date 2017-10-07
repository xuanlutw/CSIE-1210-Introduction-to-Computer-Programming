#include<stdio.h>
#include"complex.h"
 
void init(complex *c, float a, float b){
    c->re = a;
    c->im = b;
    return;
}

void complex_print(complex *x){
    if(x->im > 0)printf("%.3f+%.3fi\n", x->re, x->im);
    else printf("%.3f%.3fi\n", x->re, x->im);
    return;
}

complex complex_add(complex *x, complex *y){
    complex tmp;
    tmp.re = x->re + y->re;
    tmp.im = x->im + y->im;
    return tmp;
}

complex complex_sub(complex *x, complex *y){
    complex tmp;
    tmp.re = x->re - y->re;
    tmp.im = x->im - y->im;
    return tmp;
}

complex complex_mul(complex *x, complex *y){
    complex tmp;
    tmp.re = x->re * y->re - x->im * y->im;
    tmp.im = x->im * y->re + x->re * y->im;
    return tmp;
}
