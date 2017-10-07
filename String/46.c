#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node* next;
}Node;
 
Node* insert(Node* head, int n, char data){
    Node *tmp;
    tmp = (Node*)malloc(sizeof(Node));
    if (head == NULL){
        tmp->data = data;
        tmp->next = NULL;
        return tmp;
    }
    else if (n == 1){
        tmp->data = head->data;
        head->data = data;
        tmp->next = head->next;
        head->next = tmp;
        return head;
    }
    else{
        Node* pre = head;
        for (int i = 1;i < n - 1;++i) pre = pre->next;
        tmp->data = data;
        tmp->next = pre->next;
        pre->next = tmp;
        return head;
    }
    return NULL;
}

Node* delete(Node* head, int n){
    if (n == 1 && head->next != NULL){
        Node* tmp = head->next;
        head->data = head->next->data;
        head->next = head->next->next;
        free(tmp);
        return head;
    }
    else if(n == 1){
        free(head);
        return NULL;
    }
    else{
        Node* pre = head;
        for (int i = 1;i < n - 1;++i) pre = pre->next;
        Node *tmp = pre->next;
        pre->next = pre->next->next;
        free(tmp);
        return head;
    }
    return NULL;
}

int main(){
    char com[128];
    Node *head = NULL;
    int m = 0;
    while (fgets(com, 128, stdin) != NULL){
        if (com[0] == 'i'){
            if (com[7] == 'l') head = insert(head, 1, com[12]);
            else if (com[7] == 'r') head = insert(head, m + 1, com[13]);
            else{
                int i;
                for (i = 7;;++i){
                    if (com[i] == ' ') break;
                }
                com[i] = '\0';
                int num = atoi(com + 7);
                head = insert(head, num, com[i + 1]);
            }
            ++m;
        }
       else{
            if (com[7] == 'l') head = delete(head, 1);
            else if (com[7] == 'r') head = delete(head, m);
            else{
                int num = atoi(com + 7);
                head = delete(head, num);
            }
            --m;
        }
#ifdef DEBUG 
        printf("%d\n", m);
        Node* tt = head;
        while(tt != NULL){
            printf("%c\n", tt->data);
            tt = tt->next;
        }
#endif
    }
    int ans = 0, len = 0, lennow = 0;
    char now = '0';
    while(head != NULL){
        if (head->data == now) ++lennow;
        else{
            lennow = 1;
            now = head->data;
        }
        if (lennow == len){
            com[ans] = now;
            ++ans;
        }
        else if (lennow > len){
            com[0] = now;
            ans = 1;
            len = lennow;
        }
        head = head->next;
    }
    for (int i = 0;i < ans;++i) printf("%c ", com[i]);
    printf("%d", len);
    return 0;
}
