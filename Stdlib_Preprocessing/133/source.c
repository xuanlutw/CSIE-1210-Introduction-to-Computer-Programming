#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct string_count {
        char seen[80];
        int count;
};

int compare_and_add(char *string, struct string_count strings[]) {
    int index, fl = 1;
    for (index = 0;;++index){
        if (strings[index].count == 0) break;
        if (!strcmp(string, strings[index].seen)){
            fl = 0;
            ++strings[index].count;
            break;
        }
    }
    if (fl){
        strcpy(strings[index].seen, string);
        strings[index].count = 1;
        return 0;
    }
    return 1;
}

int compare(const void* a, const void* b){
    if (((struct string_count*)a)->count != ((struct string_count*)b)->count) return ((struct string_count*)a)->count - ((struct string_count*)b)->count;
    return strcmp(((struct string_count*)a)->seen, ((struct string_count*)b)->seen);
}

void sort(struct string_count strings[]) {
    int index;
    for (index = 0;;++index){
        if (strings[index].count == 0) break;
    }
    qsort(strings, index, sizeof(struct string_count), compare);
    return; 
}

void print(struct string_count strings[]) {
    int index;
    for (index = 0;;++index){
        if (strings[index].count == 0) break;
        printf("%d %s\n", strings[index].count, strings[index].seen);
    }
    return;
}
