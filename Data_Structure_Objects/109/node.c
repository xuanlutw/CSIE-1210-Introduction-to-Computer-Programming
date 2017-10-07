#include<stdio.h>
#include"node.h"

void print(int route[1024], int n){
    for (int i = 0;i < n;++i){
        printf("%d", route[i]);
        if (i == n - 1) printf("\n");
        else printf(" ");
    }
    return;
}

void print_paths(struct node *root, int route[1024], int n){
    route[n] = root->data;
    if (root->left == NULL && root->right == NULL) print(route, n + 1);
    if (root->left != NULL) print_paths(root->left, route, n + 1);
    if (root->right != NULL) print_paths(root->right, route, n + 1);
    return;
}

void print_all_paths(struct node *root){
    int route[1024] = {0};
    int n = 0;
    print_paths(root, route, n);
    return;
}
