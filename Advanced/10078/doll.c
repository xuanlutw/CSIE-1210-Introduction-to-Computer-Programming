#include<string.h>
#include<stdlib.h>
#include"doll.h"

Doll *newDoll(char top, char bottom){
    Doll *doll;
    doll = (Doll*)malloc(sizeof(Doll));
    doll->top = top;
    doll->bottom = bottom;
    doll->interior = NULL;
    return doll;
}

void package(Doll *outer, Doll *inter){
    outer->interior = inter;
    return;
}

void doll_contain(Doll *doll, char* buffer){
    if (doll->interior == NULL){
        buffer[0] = doll->top;
        buffer[1] = doll->bottom;
        buffer[2] = '\0';
        return;
    }
    doll_contain(doll->interior, buffer);
    char tmp[100];
    tmp[0] = doll->top;
    tmp[1] = '\0';
    strcat(tmp, buffer);
    tmp[strlen(tmp) + 1] = '\0';
    tmp[strlen(tmp)] = doll->bottom;
    strcpy(buffer, tmp);
    return;
} 
    
const char* doll_c_str(Doll *doll){
    char *ret;
    ret = (char*)malloc(100 * sizeof(char));
    doll_contain(doll, ret);
    return ret;
}

