#include<stdio.h>
#include<stdlib.h>

struct treeNode{
    int value;
    struct treeNode* parent;
    struct treeNode* left;
    struct treeNode* right;
};

struct Node{
    int value;
    int level;
};

int compare(const void* a, const void* b){
    return ((struct Node*)a)->level > ((struct Node*)b)->level;
}

void print_tree(struct treeNode* root){
    printf("%d\n", root->value);
    if(root->left != 0) print_tree(root->left);
    if(root->right != 0) print_tree(root->right);
    return;
}

void add_tree(struct treeNode* root, int value){
    if (value > root->value){
        if (root -> right == NULL){
            struct treeNode* tn;
            tn = (struct treeNode*) malloc(sizeof(struct treeNode));
            tn->value = value;
            tn->parent = root;
            tn->right = NULL;
            tn->left = NULL;
            root->right = tn;
        }
        else add_tree(root->right, value);
    }
    else{
        if (root -> left == NULL){
            struct treeNode* tn;
            tn = (struct treeNode*) malloc(sizeof(struct treeNode));
            tn->value = value;
            tn->parent = root;
            tn->right = NULL;
            tn->left = NULL;
            root->left = tn;
        }
        else add_tree(root->left, value);
    }
    return;
}

struct treeNode* find_location(struct treeNode* root, int value){
    if (value == root->value) return root;
    if (value > root->value && root->right != NULL) return find_location(root->right, value);
    if (value < root->value && root->left != NULL) return find_location(root->left, value);
    return NULL;
}

int noback_tree_distance(struct treeNode* now, int value){
    if (value == now->value) return 0;
    if (value > now->value){
        int fl = -1;
        if (now->right != NULL) fl = noback_tree_distance(now->right, value);
        if (fl == -1) return -1;
        else return fl + 1;
    }
    if (value < now->value){
        int fl = -1;
        if (now->left != NULL) fl = noback_tree_distance(now->left, value);
        if (fl == -1) return -1;
        else return fl + 1;
    }
    return -1;
}

int tree_distance(struct treeNode* now, int value){
    if (value == now->value) return 0;
    if (value > now->value){
        int fl = -1;
        if (now->right != NULL) fl = noback_tree_distance(now->right, value);
        if (now->parent != NULL && fl == -1) fl = tree_distance(now->parent, value);
        if (fl == -1) return -1;
        else return fl + 1;
    }
    if (value < now->value){
        int fl = -1;
        if (now->left != NULL) fl = noback_tree_distance(now->left, value);
        if (now->parent != NULL && fl == -1) fl = tree_distance(now->parent, value);
        if (fl == -1) return -1;
        else return fl + 1;
    }
    return -1;
}

int  main(){
    int n;
    scanf("%d", &n);
    struct Node node[n];
    for (int i = 0;i < n;++i) scanf("%d%d", &(node[i].value), &(node[i].level));
    qsort(node, n, sizeof(struct Node), compare);
    struct treeNode* root;
    root = (struct treeNode*) malloc(sizeof(struct treeNode));
    if (n){
        root->value = node[0].value;
        root->parent = NULL;
        root->left = NULL;
        root->right = NULL;
    }
    for (int i = 1;i < n;++i) add_tree(root, node[i].value);
    //print_tree(root);
    int p;
    scanf("%d", &p);
    int p1, p2;
    while(p--){
        scanf("%d%d", &p1, &p2);
        struct treeNode* loc1;
        loc1 = find_location(root, p1);
        printf("%d\n", tree_distance(loc1, p2));
    }
    return 0;
}
