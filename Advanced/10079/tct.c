#include<stdio.h>
#include<string.h>
#include"tct.h"
 
/*
typedef struct Directory {
    char name[256];
    struct Directory *childDir;
    struct Directory *silbingDir;
} Directory;
*/
 
void tree_with_level(Directory *fs, int level, int preDir){
    for (int i = 0;i < level;++i){
        if (preDir & (1 << i)) printf("|");
        else printf(" ");
        printf("  ");
    }
    printf("+- %s\n", fs->name);
    if (fs->silbingDir != NULL && level) preDir = preDir | (1 << level);
    else preDir = preDir & ~(1 << level);
    if (fs->childDir != NULL){
        preDir = preDir | (1 << (level + 1));
        for (int i = 0;i <= level;++i){
            if (preDir & (1 << i)) printf("|");
            else printf(" ");
            printf("  ");
        }
        printf("|\n");
        tree_with_level(fs->childDir, level + 1, preDir);
        preDir = preDir & ~(1 << (level + 1));
    }
    if (fs->silbingDir != NULL && level){
        for (int i = 0;i < level;++i){
            if (preDir & (1 << i)) printf("|");
            else printf(" ");
            printf("  ");
        }
        printf("|\n");
        tree_with_level(fs->silbingDir, level, preDir);
    }
    return;
}

void tree(Directory *fs){
    tree_with_level(fs, 0, 0);
    return;
}

Directory* cd(Directory *fs, char path[]){
    int i, fl = 1;
    for (i = 0;i < strlen(path);++i){
        if (path[i] == '/'){
            fl = 0;
            break;
        }
    }
    path[i] = '\0';
    Directory* target;
    target = fs->childDir;
    while (1){
        if (target == NULL) break;
        if (!strcmp(target->name, path)) break;
        target = target->silbingDir;
    } 
    if (target == NULL) return NULL;
    else{
        if (fl) return target;
        else{
            path[i] = '/';
            return cd(target, path + i + 1);
        }
    }
    return NULL;
}
