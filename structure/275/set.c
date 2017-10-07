#include<stdio.h>
#include"set.h"

void init(Set *set){
    *set = 0;
    return;
}

void add(Set *set, int i){
    if (!(*set & ((long long)1 << i))) *set += ((long long)1 << i);
    return;
}

void has(Set set, int i){
    if (set & ((long long)1 << i)) printf("set has %d\n", i);
    else printf("set does not have %d\n", i);
}

Set setUnion(Set a, Set b){
    return a | b;
}

Set setIntersect(Set a, Set b){
    return a & b;
}

Set setDifference(Set a, Set b){
    return a ^ b;
}
