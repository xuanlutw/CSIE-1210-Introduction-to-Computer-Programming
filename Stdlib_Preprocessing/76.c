#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
}

int main(){
    char buffer[65][40];
    int n;
    for (n = 0;fgets(buffer[n], 40, stdin) != NULL;++n);
    qsort(buffer, n, sizeof(buffer[0]), compare);
    for (int i = 0;i < n;++i) printf("%s", buffer[i]);
    return 0;
}
