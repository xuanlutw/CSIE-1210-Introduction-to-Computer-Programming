#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char data[510];
    struct node* next;
    struct node* pre;
}Node;

void insert(char* tmp, Node* head){
    if (!strcmp(tmp, head->data)) return;
    else if (strcmp(tmp, head->data) > 0 && head->next == NULL){
        Node* tmpn;
        tmpn = (Node*)malloc(sizeof(Node));
        strcpy(tmpn->data, tmp);
        tmpn->next = NULL;
        tmpn->pre = head;
        head->next = tmpn;
    }
    else if (strcmp(tmp, head->data) > 0) insert(tmp, head->next);
    else{
        Node* tmpn;
        tmpn = (Node*)malloc(sizeof(Node));
        strcpy(tmpn->data, tmp);
        tmpn->next = head;
        tmpn->pre = head->pre;
        head->pre->next = tmpn;
        head->pre = tmpn;
    }
    return;
}

int main(){
    char target[510];
    scanf("%s", target);
    Node head;
    head.data[0] = '\0';
    head.next = NULL;
    head.pre = NULL;
    for (int i = 0;i < strlen(target);++i){
        for (int j = i + 1;j <= strlen(target);++j){
            char tmp[510];
            strcpy(tmp, target + i);
            tmp[j - i] = '\0';
            insert(tmp, &head);
        }
    }
    Node* index = head.next;
    /*while (1){
        printf("%s\n", index->data);
        if (index->next == NULL) break;
        index = index-> next;
    }*/
    return 0;
}
    
