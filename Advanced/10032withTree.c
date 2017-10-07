#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char data[510];
    struct node* right;
    struct node* left;
}Node;

void print_tree(Node* head){
    if(head->left != NULL) print_tree(head->left);
    printf("%s\n", head->data);
    if(head->right != NULL) print_tree(head->right);
    return;
}

void insert(char* tmp, Node* head){
    if (!strcmp(tmp, head->data)) return;
    else if (strcmp(tmp, head->data) > 0 && head->right == NULL){
        Node* tmpn;
        tmpn = (Node*)malloc(sizeof(Node));
        strcpy(tmpn->data, tmp);
        tmpn->right = NULL;
        tmpn->left = NULL;
        head->right = tmpn;
    }
    else if (strcmp(tmp, head->data) > 0) insert(tmp, head->right);
    else if (strcmp(tmp, head->data) < 0 && head->left == NULL){
        Node* tmpn;
        tmpn = (Node*)malloc(sizeof(Node));
        strcpy(tmpn->data, tmp);
        tmpn->right = NULL;
        tmpn->left = NULL;
        head->left = tmpn;
    }
    else if (strcmp(tmp, head->data) < 0) insert(tmp, head->left);
    return;
}

int main(){
    char target[510];
    scanf("%s", target);
    Node head;
    head.data[0] = '\0';
    head.left = NULL;
    head.right = NULL;
    for (int i = 0;i < strlen(target);++i){
        for (int j = i + 1;j <= strlen(target);++j){
            char tmp[510];
            strcpy(tmp, target + i);
            tmp[j - i] = '\0';
            insert(tmp, &head);
        }
    }
    print_tree(head.right);
    return 0;
}
    
