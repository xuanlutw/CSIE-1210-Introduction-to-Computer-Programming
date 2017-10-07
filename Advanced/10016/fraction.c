#include "fraction.h"

long long gcd(long long a, long long b){
    if (!b) return a;
    return gcd(b, a % b);
}

Frac normal(long long a, long long b) {
    Frac frac;
    frac.a = a / gcd(a, b);   
    frac.b = b / gcd(a, b);
    return frac;    
}

Frac add(Frac x, Frac y) {
    long long a, b;
    b = x.b * y.b / gcd(x.b, y.b);
    a = (y.b * x.a + x.b * y.a) / gcd(x.b, y.b);
    Frac frac;
    frac.a = a / gcd(a, b);   
    frac.b = b / gcd(a, b);
    return frac;    
}

Frac subtract(Frac x, Frac y) {
    long long a, b;
    b = x.b * y.b / gcd(x.b, y.b);
    a = (y.b * x.a - x.b * y.a) / gcd(x.b, y.b);
    Frac frac;
    frac.a = a / gcd(a, b);   
    frac.b = b / gcd(a, b);
    return frac;    
}

Frac multipy(Frac x, Frac y) {
    int t;
    t = gcd(x.a, x.b);
    x.a /= t;
    x.b /= t;
    t = gcd(y.a, y.b);
    y.a /= t;
    y.b /= t;
    t = gcd(x.a, y.b);
    x.a /= t;
    y.b /= t;
    t = gcd(y.a, x.b);
    y.a /= t;
    x.b /= t;
    x.a *= y.a;
    x.b *= y.b;
    return x;
}
Frac divide(Frac x, Frac y) {
    int t;
    t = gcd(x.a, x.b);
    x.a /= t;
    x.b /= t;
    t = gcd(y.a, y.b);
    y.a /= t;
    y.b /= t;
    t = gcd(x.a, y.a);
    x.a /= t;
    y.a /= t;
    t = gcd(y.b, x.b);
    y.b /= t;
    x.b /= t;
    x.a *= y.b;
    x.b *= y.a;
    return x;
}
