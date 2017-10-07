#include<stdio.h>
#include<stdlib.h>

struct treeNode{
    int value;
    struct treeNode *left;
    struct treeNode *right;
};

void HRHL(struct treeNode* root);
void HLHR(struct treeNode* root);

void HRHL(struct treeNode* root){
    printf("%d\n", root->value);
    if (root->right != NULL) HLHR(root->right);
    printf("%d\n", root->value);
    if (root->left != NULL) HLHR(root->left);
    return;
}

void HLHR(struct treeNode* root){
    printf("%d\n", root->value);
    if (root->left != NULL) HRHL(root->left);
    printf("%d\n", root->value);
    if (root->right != NULL) HRHL(root->right);
    return;
}
    
int str_to_int(char* row){
    int ans = 0;
    for (int i = 0;i < 100;++i){
        if (row[i] == '\0') break;
        ans = ans * 10 + row[i] - '0';
    }
    return ans;
}

struct treeNode* construct_tree(char *row){
    if (row[0] <= '9' && row[0] >= '0'){
        struct treeNode *root;
        root = (struct treeNode*) malloc(sizeof(struct treeNode));
        root->left = NULL;
        root->right = NULL;
        root->value = str_to_int(row);
        return root;
    }
    else{
        struct treeNode *root;
        root = (struct treeNode*) malloc(sizeof(struct treeNode));
        char tmp[4096];
        int comma, end, fl = 0;
        for (comma = 1;comma < 4096;++comma){
            if (*(row + comma) == ',' && !fl) break;
            if (*(row + comma) == '(') ++fl;
            if (*(row + comma) == ')') --fl;
            tmp[comma - 1] = *(row + comma);
        }
        tmp[comma - 1] = '\0';
        root->left = construct_tree(tmp);
        for (end = 1;end < 4096;++end){
            if (*(row + comma + end) == '\0') break;
            tmp[end - 1] = *(row + comma + end);
        }
        tmp[end - 2] = '\0';
        root->right = construct_tree(tmp);
        root->value = root->left->value + root->right->value;
        return root;
    }
    return NULL;
}

int main(){
    char row[4096];
    scanf("%s", row);
    struct treeNode *root = construct_tree(row);
    HLHR(root);
    return 0;
}    
