#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct treeNode{
    char value[40];
    struct treeNode* left;
    struct treeNode* right;
};

struct variable{
    char name[40];
    int value;
};

/*void print_tree(struct treeNode* root){
    if (root->right == NULL) printf("%s\n", root->value);
    else{
        printf("%s\n", root->value);
        print_tree(root->left);
        print_tree(root->right);
    }
    return;
}*/

struct treeNode* construct_tree(){
    char tmp[40];
    struct treeNode* root;
    root = (struct treeNode*) malloc(sizeof(struct treeNode));
    scanf("%s", tmp);
    if (!strcmp(tmp, "(")){
        scanf("%s", tmp);
        strcpy(root->value, tmp);
        root->left = construct_tree();
        root->right = construct_tree();
        scanf("%s", tmp); //')'
    }
    else{
        strcpy(root->value, tmp);
        root->left = NULL; 
        root->right = NULL; 
    }
    return root;
}

int analysis(char* tmp, struct variable* var, int n){
    for (int i = 0;i < n;++i){
        if (!strcmp(tmp, (var + i)->name)) return (var + i)->value;
    }
    int ans = 0;
    for (int i = 0;;++i){
        if (*(tmp + i) == '\0') break;
        ans = ans * 10 + *(tmp + i) - '0';
    }
    return ans;
}

int cal_tree(struct treeNode* root, struct variable* var, int n){
    if (root->left == NULL) return analysis(root->value, var, n);
    if (!strcmp(root->value, "+")) return cal_tree(root->left, var, n) + cal_tree(root->right, var, n); 
    if (!strcmp(root->value, "-")) return cal_tree(root->left, var, n) - cal_tree(root->right, var, n); 
    if (!strcmp(root->value, "*")) return cal_tree(root->left, var, n) * cal_tree(root->right, var, n); 
    if (!strcmp(root->value, "/")) return cal_tree(root->left, var, n) / cal_tree(root->right, var, n); 
    return -1;
}

int main(){
    struct treeNode* root;
    root = construct_tree();
    //print_tree(root);
    struct variable var[64];
    char tmps[40];
    int tmpi, n;
    for (n = 0;scanf("%s %*s %d", tmps, &tmpi) != EOF;++n){
        var[n].value = tmpi;
        strcpy(var[n].name, tmps);
    }
    printf("%d", cal_tree(root, var, n));
}
